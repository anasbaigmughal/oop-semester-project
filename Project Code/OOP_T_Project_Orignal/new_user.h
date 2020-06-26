#pragma once
#include "user.h"
#include "string"
#include "string.h"
#include "fstream"
#include <iostream>
using namespace std;

class new_user:public user
{
public:
	new_user(void); //constructor
	void getData(); //get input of username and password from user
};

