#include "iomanip"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "new_user.h"
#include "old_user.h"
#include "transaction.h"
#include "income.h"
#include "expense.h"
#include "user.h"
#include "string"
#include "string.h"
#include "conio.h"
#include "fstream"
#include <iostream>
using namespace std;

int main()
{
	system("CLS");
	cout<<endl<<"================================================================================";
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (  m_hConsole, 
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_BLUE );
 
 
	std::cout <<"      B A H R I A - U N I V E R S I T Y - S P E N D I N G - T R A C K E R       ";
 
    SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	cout<<"================================================================================"<<endl;
	int choice1, choice2, choice3, choice4; //variables to get user choices
	user *u; //pointer to user class
	transaction *t; //pointer to transaction class
	cout<<"Enter Mode:"<<endl; 
	cout<<"1. Sign Up."<<endl;
	cout<<"2. Log In."<<endl;
	cin>>choice1; //gets mode input
	if(choice1==1)
	{
		u = new new_user; //dynamic memory allocation | polymorphism used
	}
	else
	{
		u = new old_user; //dynamic memory allocation | polymorphism used
	}
	u->getData(); //gets transaction(income/expense) data from user
	system("CLS");
	cout<<endl<<"================================================================================";
//	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (  m_hConsole, 
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_BLUE );
 
 
	std::cout <<"      B A H R I A - U N I V E R S I T Y - S P E N D I N G - T R A C K E R       ";
 
    SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	cout<<"================================================================================"<<endl;
	cout<<endl;
	system("CLS");
	cout<<endl<<"================================================================================";
	//HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (  m_hConsole, 
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_BLUE );
 
 
	std::cout <<"      B A H R I A - U N I V E R S I T Y - S P E N D I N G - T R A C K E R       ";
 
    SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	cout<<"================================================================================"<<endl;
	do
	{
	cout<<"Enter Operation:"<<endl;
	cout<<"1. Income."<<endl;
	cout<<"2. Expense."<<endl;
	cout<<"3. Display Account Balance."<<endl;
	cout<<"4. Display All Transactions."<<endl;
	cin>>choice2; //gets operation choice
	if(choice2==1)
	{
		t = new income; //dynamic memory allocation | polymorphism used
		t->getAmount(u->getUsername(), u->getPassword()); //files of the user will be created on its username.txt(final balance) and password.txt(transactions details)
	}
	else if (choice2==2)
	{
		t = new expense; //dynamic memory allocation | polymorphism used
		t->getAmount(u->getUsername(), u->getPassword()); //files of the user will be created on its username.txt(final balance) and password.txt(transactions details)
	}
	else if(choice2==3)
	{
		t= new income; //dynamic memory allocation | polymorphism used
		string s =  u->getUsername();
		(*t) + s; //operator overloaded which takes username as argument to open username.txt
	}
	else
	{
		t= new expense;  //dynamic memory allocation | polymorphism used
		t->displayTransaction(u->getPassword()); //files of the user will be created on its username.txt(final balance) and password.txt(transactions details)
	}

	/*system("CLS");
	cout<<endl<<"================================================================================";
	//HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (  m_hConsole, 
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_BLUE );
 
 
	std::cout <<"      B A H R I A - U N I V E R S I T Y - S P E N D I N G - T R A C K E R       ";
 
    SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	cout<<"================================================================================"<<endl;*/

	cout<<endl;
	cout<<endl<<"Do you want to do operation again?"<<endl;
	cout<<"1. YES."<<endl;
	cout<<"2. NO."<<endl;
	cin>>choice4;
	}
	while(choice4 == 1);
		system("CLS");
	cout<<endl<<"================================================================================";
    SetConsoleTextAttribute (  m_hConsole, 
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_BLUE );
 
 
	std::cout <<"      B A H R I A - U N I V E R S I T Y - S P E N D I N G - T R A C K E R       ";
 
    SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );
	cout<<"================================================================================"<<endl;
	
	cout<<endl<<"Enter Operation:"<<endl;
	cout<<"1. Display Account Balance."<<endl;
	cout<<"2. Display All Transactions."<<endl;
	cin>>choice3;
	if(choice3==1)
	{
		string s = u->getUsername();
		(*t) + s; //operator overloaded which takes username as argument to open username.txt
	}
	else
	{
		t= new expense;
		t->displayTransaction(u->getPassword()); //functions gets password as argument which will open password.txt file for transaction details
	}
	getch();
}