#include "iomanip"
#include "income.h"
#include "transaction.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

income::income(void) //constructor
{
}

void income::setZero(string username, string password ) //gets username and password to create 2 files, first one will get final balace details while second one will get all transaction details
{
	this->amount=0; //set to zero
	this->balance=0; //set to zero
	ofstream username_write(username.c_str(), ios::binary); //file write mode open to store final balance 
	username_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	username_write.close(); //file close
	ofstream password_write(password.c_str(), ios::binary); //file write mode open to store all transactions
	password_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
	password_write.close(); //file close
}

void income::getAmount(string username, string password)
{
	int temp_amount; //temporary amount storing variable
	cout<<"Enter Income Amount:"<<endl;
	cin>>temp_amount; //gets input
	ifstream username_read(username.c_str(), ios::binary); //file open read mode to get final balance
	username_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object from file
	balance = balance + temp_amount; //adds amount to fianl balance
	username_read.close(); //file close
	this->amount = temp_amount; //sets amount
	cout<<endl<<"Enter Transaction Category(e.g. gift, holiday, shopping etc.):"<<endl;
	cin>>this->category; //transaction type
	cout<<endl<<"Enter Transaction Place:"<<endl;
	cin>>this->place; //transaction location
	this->d.getInput(); //date input
	ofstream username_write(username.c_str(), ios::binary); //file write mode open for final balance reading
	username_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //reads object form file
	username_write.close(); //fiel close
	//-----------------------Above is work with username.txt file which only has 1 record for final balance------
	//-----------------------Below is work with password.txt file which contains transactions list------
	ofstream password_write(password.c_str(), ios::binary|ios::app); //file write mode open to read transactions details
	password_write.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes objec tto file
	password_write.close(); //file close
}

void income::displayTransaction(string password) //displays all transactions
{
	ifstream file_read(password.c_str(), ios::binary); //file read mode open to read tranasaction details
	cout<<"================================================================================";
	cout<<setw(20)<<"TRANSACTION AMOUNT";
	cout<<setw(12)<<"CATEGORY";
	cout<<setw(10)<<"PLACE";
	cout<<setw(18)<<"FINAL BALANCE";
	cout<<setw(12)<<"DATE"<<endl;
	cout<<"================================================================================"<<endl;
	for(int i=0;!file_read.eof();i++) //continues untill EOF reaches
	{
	file_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object from file
			if(i==0) //skips garbage data
			{
				continue;
			} 
	cout<<setw(20)<<amount<<setw(12)<<category<<setw(10)<<place<<setw(18)<<balance;
	cout<<setw(9);
	d.displayDate();
	cout<<endl;
	}
}

void income:: operator + (string username) //operator overloaded to display final balance
{
	ifstream username_read(username.c_str(), ios::binary); //file read mode open to read final balance
	username_read.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object form file
	cout<<endl<<"Account Balance: "<<this->balance<<endl; 
	username_read.close(); //file close
}
