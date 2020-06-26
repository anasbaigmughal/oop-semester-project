#include "expense.h"
#include "iomanip"
#include "transaction.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

expense::expense(void) //constructor
{
}

void expense::setZero(string username, string password ) //sets all values to zero
{
	this->amount=0; //set to zero
	this->balance=0; //set to zero
	ofstream username_write(username.c_str(), ios::binary); //file write mode open to store final balance
	username_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	username_write.close(); //file close
	ofstream password_write(password.c_str(), ios::binary); //file write mode open to store transaction details to file
	password_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	password_write.close(); //file close
}

void expense::getAmount(string username, string password) //gets input from user
{
	int temp_amount; //temporary amount storing variable
	cout<<"Enter Expense Amount:"<<endl;
	cin>>temp_amount; //amount input
	temp_amount = (temp_amount * (-1)); //set debit amount to -ve so that when all transactions are displayed user could identify which one is income and which one is expense
	ifstream username_read(username.c_str(), ios::binary); //file read mode open to store final balance
	username_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object form file
	balance = balance + temp_amount; //adds amount to final balance
	username_read.close(); //file close
	this->amount = temp_amount; //amount set
	cout<<endl<<"Enter Transaction Category(e.g. gift, holiday, shopping etc.):"<<endl;
	cin>>this->category; //gets transaction type
	cout<<endl<<"Enter Transaction Place:"<<endl;
	cin>>this->place; //gets transaction location
	this->d.getInput(); //gets date input
	ofstream username_write(username.c_str(), ios::binary); //file wriite mode open tos tore final balance
	username_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	username_write.close(); //file close
	//-----------------------Above is work with username.txt file which only has 1 record for final balance------
	//-----------------------Below is work with password.txt file which contains transactions list------
	ofstream password_write(password.c_str(), ios::binary|ios::app); //file write mode open to store transaction details
	password_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	password_write.close(); //file close
}

void expense::displayTransaction(string password) //displays all transactions
{
	ifstream file_read(password.c_str(), ios::binary); //file read mode open to get transactions details
	cout<<"================================================================================";
	cout<<setw(20)<<"TRANSACTION AMOUNT";
	cout<<setw(12)<<"CATEGORY";
	cout<<setw(10)<<"PLACE";
	cout<<setw(18)<<"FINAL BALANCE";
	cout<<setw(12)<<"DATE"<<endl;
	cout<<"================================================================================"<<endl;
	for(int i=0;!file_read.eof();i++) //read file untill EOF
	{
	file_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object form file
			if(i==0) //skips garbage data
			{
				continue;
			} 
			if(file_read.eof()) //skips last iteration after EOF
			{
				break;
			}
	cout<<setw(20)<<amount<<setw(12)<<category<<setw(10)<<place<<setw(18)<<balance;
	cout<<setw(9);
	d.displayDate();
	cout<<endl;
	}
}

void expense:: operator + (string username) //diplays final balance
{
	ifstream username_read(username.c_str(), ios::binary); //file read mode open to read final balance
	username_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object from file
	cout<<endl<<"Account Balance: "<<this->balance<<endl;
	username_read.close(); //file close
}
