/*
 * ReadInMembers.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Alex
 */

#include "header.h"
/*************************************************************************
* ReadInMembers
* ________________________________________________________________________
* This function reads in member information from a text file and creates
* 	a list in a BulkClub variable
* ________________________________________________________________________
* PRE-CONDITIONS
*	strawberryClub : Contains an empty list of members
* POST-CONDITIONS
*	strawberryClud : Contains a list of members from an input file
**************************************************************************/
void ReadInMembers(BulkClub &strawberryClub)
{
	ifstream inFile;
	string name;
	long membershipNum;
	string memType;
	string month;
	string day;
	string year;
	Date   *newDate;
	BasicMember     *bMember;

	inFile.open("warehouseshoppers.txt");

	while(!(inFile.eof()))
	{
		getline(inFile, name);
		inFile >> membershipNum;
		inFile.ignore(1000, '\n');
		getline(inFile, memType);
		getline(inFile, month, '/');
		getline(inFile, day, '/');
		getline(inFile, year);
		newDate = new Date(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()));

		if(memType == "Basic")
		{
			bMember = new BasicMember(name, membershipNum, memType, *newDate, 0.0);

			strawberryClub.AddMember(bMember);
		}
		else
		{
			bMember = new PreferredMember(name, membershipNum, memType, *newDate, 0.0, 0.0);

			strawberryClub.AddMember(bMember);
		}
	}

	inFile.close();
}



