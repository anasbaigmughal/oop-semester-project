#pragma once
#include "user.h"
#include "fstream"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

class old_user : public user //inheritance applied base class 'user'
{
public:
	old_user(void); //constructor
	void getData(); //function to get input of USERNAME and PASSWORD from user
};

