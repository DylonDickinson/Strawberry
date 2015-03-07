/*************************************************************************
* AUTHOR            : Dude
* STUDENT ID        : 355763
* ASSIGNMENT #6     : Saddleback Bank - OOP
* CLASS     	    : CS 1B
* SECTION  			: TTh 8:00 - 11:50
* DUE DATE  		: 12/9/14
**************************************************************************/
#include "Date.h"

/************************************************************************
    CONSTRUCTORS & DESTRUCTOR
 ************************************************************************/

Date::Date()
{
	dateMonth = 0;
	dateDay   = 0;
	dateYear  = 0;
}

Date::Date(int month,
		   int day,
		   int year)
{
	SetDate(month, day, year);
}

Date::~Date() { }

/************************************************************************
	 MUTATORS
	-------------------------------------------------------------------
	 SetDate
 ************************************************************************/

// Sets the date given a month day and year
//    Checks to see if the date is valid prior to setting the date
void Date::SetDate(int month,
				   int day,
				   int year)
{
//	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//	int currentYear;
//	int currentMonth;
//	int currentDay;
//	int lastDayInMonth;
//	tm *currentTime;     // Used to find the current time
//
//	// Find the current year based on the currentTime
//	time_t now  = time(0);
//	currentTime  = localtime(&now);
//	currentYear  = 1900 + currentTime->tm_year;
//	currentMonth = 1 + currentTime->tm_mon;
//	currentDay   = currentTime->tm_mday;
//
//	// ERROR CHECK - The year, month & day
//	//    YEAR: The year must be between 1900 and the currentYear
//	if(year > currentYear || year < 1900)
//	{
//		cout << "\n*** Invalid Year ***\n";
//		cout << "Your year was " << year
//			 << " and the current year is " << currentYear << endl;
//	}
//	//    MONTH: The month must be between 0 and 12 or
//	//           <=  currentMonth for the currentYear
//	else if ((year != currentYear && (month > 12 || month < 0)) ||
//			 (year == currentYear && month > currentMonth))
//	{
//		cout << "\n*** Invalid Month ***\n\n";
//	}
//	//    DAY:  The day must be <= the # of days in the month
//	//          This also account for Leap Year
//	else
//	{
//		lastDayInMonth = daysInMonth[month - 1];
//
//		// LEAP YEAR Adjustment to lastDayInMonth
//		if(month == 2 &&
//		  ((year % 4 == 0 || year % 400 == 0) &&
//		    year % 100 != 0))
//		{
//			lastDayInMonth++;
//		}
//
//		// Check if Day is valid
//		if ((day > lastDayInMonth || day < 0) ||
//			(year == currentYear && month == currentMonth &&
//			 day > currentDay))
//		{
//			cout << "\n*** Invalid day ***\n\n";
//		}
//		else
//		{
			// Set the Date (if it is valid)
			dateMonth = month;
			dateDay   = day;
			dateYear  = year;
//
//		} // END - DAY CHECK
//	} // END - YEAR - MONTH If-else-if
}

/******************************************************
     ACCESSORS
    ------------------------------------------------
	 GetDate
	 GetYear
	 GetMonth
	 GetDay
	 DisplayDate
 ******************************************************/
void Date::GetDate(int &month,
				   int &day,
				   int &year) const
{
	  month = dateMonth;
	  day   = dateDay;
	  year  = dateYear;
}

int  Date::GetYear() const
{
	return dateYear;
}

int  Date::GetMonth() const
{
	return dateMonth;
}

int  Date::GetDay() const
{
	return dateDay;
}

bool Date::CompareDate(Date dateToCompare) const
{
	bool equal = false;
	if(Date::GetDay() == dateToCompare.dateDay &&
	   Date::GetMonth() == dateToCompare.dateMonth &&
	   Date::GetYear() == dateToCompare.dateYear)
	{
		equal = true;
	}

	return equal;
}

string Date::DisplayDate() const
{
	ostringstream dateOut;

	// Check if Day or Month are < 10 and add a leading 0 if necessary
	if (dateMonth < 10)
	{
		dateOut << '0';
	}
	dateOut << dateMonth << '/';
	if (dateDay < 10)
	{
		dateOut << '0';
	}
	dateOut << dateDay   << '/'
		 << dateYear;

	return dateOut.str();
}

