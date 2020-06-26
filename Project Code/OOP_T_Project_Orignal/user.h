#pragma once
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

class user
{
protected:
	string username;
	string password;
public:
	user(void);
	virtual void getData()=0; //pure virtual function to apply polymorphism and get Username and Password from User
	string getUsername(); //get variable method
	string getPassword(); //get variable method
};

