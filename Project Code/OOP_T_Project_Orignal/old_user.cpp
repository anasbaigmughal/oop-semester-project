#include "old_user.h"
#include "user.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

old_user::old_user(void) //constructor
{
}

void old_user::getData() //variable to get input data from user
{
	int checkpoint; //variable to store check value
	string temp_username; //temporary username variable
	string temp_password; //temporary password variable
	do //loop to get input from user as many times he wants
	{
	checkpoint=0; //set to 0
	cout<<"Enter Username:"<<endl;
	cin>>temp_username; //username input
	cout<<endl<<"Enter Password:"<<endl;
	cin>>temp_password; //password input
	ifstream read_file("credentials.txt", ios::binary); //read mode file open which contains usernames and passwords of all users
	for( ;!(read_file.eof()); ) //no initialization or increment statements because there we only check loop with EOF
	{
		read_file.read(reinterpret_cast<char *>(this), sizeof(*this)); //reading credentials file
		if((temp_username==this->username) && (temp_password==this->password)) //it checks either username and password are correct or not
		{
			checkpoint=1; //if username and password are entered correctly
		}
	}
	if(checkpoint==0) //if username or password is incorrectly typed
	{
		cout<<"Incorrect USERNAME or PASSWORD!!! TRY AGAIN"<<endl<<endl;
	}
	read_file.close(); //file close
	}
	while(checkpoint==0); //let it get input from user unless correct username and password is entered (i.e. checkpoint=1)
	if(checkpoint==1) //condition for username and password are correctly typed
	{
		this->username = temp_username; //stores username to object 
		this->password = temp_password; //stores password to object 
	}
}
