#include "user.h"
#include "string"
#include "string.h"
#include <iostream>
using namespace std;

user::user(void)
{
}

string user::getUsername() //get variable method
{
	return(username);
}

string user::getPassword() //get variable method
{
	return(password);
}