#pragma once
#include "fstream"
#include "date.h"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;


class transaction
{
protected:
	int amount; //transaction amount
	int balance; //final balance
	string category; //type of transaction
	string place; //place where transaction made
	Date d; //to store date of transaction
public:
	transaction(void); //constructor
	virtual void getAmount(string, string)=0; //function to get input from user
	virtual void displayTransaction(string)=0; //function to display all transactions
	virtual void operator + (string)=0; //operator overloaded to display final balance in account
};

