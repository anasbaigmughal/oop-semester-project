#include "Date.h"
#include<iostream>
using namespace std;

Date::Date(void)
{
}

void Date::getInput()
{
	cout<<endl<<"Enter Date:-"<<endl;
	cout<<"Day:"<<endl;
	cin>>day;
	cout<<"Month:"<<endl;
	cin>>month;
	cout<<"Year:"<<endl;
	cin>>year;
}

void Date::displayDate()
{
	cout<<day<<"/"<<month<<"/"<<year;
}