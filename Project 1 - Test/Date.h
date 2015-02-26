/*************************************************************************
* AUTHOR            : Dude
* STUDENT ID        : 355763
* ASSIGNMENT #6     : Saddleback Bank - OOP
* CLASS     	    : CS 1B
* SECTION  			: TTh 8:00 - 11:50
* DUE DATE  		: 12/9/14
**************************************************************************/
#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

class Date
{
public:

	/*****************************************************
	     CONSTRUCTORS & DESTRUCTOR
	 *****************************************************/
	Date();
	Date(int month,
		 int day,
		 int year);

	~Date();

	/*****************************************************
	     MUTATORS
	 *****************************************************/
	void SetDate(int month,
			     int day,
				 int year);

	/******************************************************
	    ACCESSORS
	 ******************************************************/
	void GetDate(int &month,
				 int &day,
				 int &year) const;
	int  GetYear()  const;
	int  GetMonth() const;
	int  GetDay()   const;
	bool CompareDate(Date dateToCompare) const;

	// Displays in MM/DD/YYYY format
	string DisplayDate() const;


private:
	int dateMonth;
	int dateDay;
	int dateYear;
};

#endif /* DATE_H_ */
