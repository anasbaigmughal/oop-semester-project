#pragma once
#include "transaction.h"
#include "date.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

class expense:public transaction
{
public:
	expense(void); //constructor
	void setZero(string, string); //set all variables  to zero
	void getAmount(string, string); //gets input from user
	void displayTransaction(string); //displays all transactions
	void operator + (string); //operator overloaded to display final balance of account
};

