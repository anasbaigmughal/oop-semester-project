#pragma once
#include "transaction.h"
#include "date.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

class income:public transaction //inheritance applied base class 'transaction'
{
public:
	income(void); //constructor
	void setZero(string, string); //sets all variables to 0 of income class, also takes username and password as arguments to make file names
	void getAmount(string, string); //gets user input
	void displayTransaction(string); //displays all transactions
	void operator + (string); //operator overloaded to display Account balance (argument is filename of the user which contains its all log)
};

