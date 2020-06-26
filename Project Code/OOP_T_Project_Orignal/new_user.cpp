#include "new_user.h"
#include "income.h"
#include "user.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

new_user::new_user(void) //constructor
{
}

void new_user::getData() //get input from user
{
	int checkpoint; //variable to store check value
	string temp_username; //stores username temporarily
	string temp_password; //stores password temporarily
	do //asks user for choices and operaations as many times he want to do operations
	{
	checkpoint=0; //set to zero
	cout<<"Enter Username:"<<endl;
	cin>>temp_username; //get username
	cout<<endl<<"Enter Password:"<<endl;
	cin>>temp_password; //gets password
	ifstream read_file("credentials.txt", ios::binary); //file open read mode to check either entered username is already registered or not
	for( ;!(read_file.eof()); ) //checks for EOF, no intialization or increment statements necassary
	{
		read_file.read(reinterpret_cast<char *>(this), sizeof(*this)); //reads object from file
		if(temp_username == this->username) //if entered username is registered
		{
			cout<<"Username Already Found."<<endl<<endl;
			checkpoint=1; //set to 1
		}
	}
	read_file.close(); //file close
	}
	while(checkpoint==1); //continues loop unless checkpoint=1 (i.e. username already registered)
	if(checkpoint==0) //if duplicate usernaem not found
	{
		this->username = temp_username; //stores username to object
		this->password = temp_password; //stores password to object
		income i; //income class object
		i.setZero(this->username, this->password); //this function sets all variables of income class to 0
		ofstream write_file("credentials.txt",ios::binary|ios::app); //file write mode open to save new user login information to file
		write_file.write(reinterpret_cast<char *>(this), sizeof(*this)); //writes object to file
		write_file.close(); //file close
	}
}