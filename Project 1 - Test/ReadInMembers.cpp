/*
 * ReadInMembers.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Alex
 */

#include "header.h"

BulkClub ReadInMembers()
{
	ifstream inFile;
	string name;
	long membershipNum;
	string memType;
	string month;
	string day;
	string year;
	Date   *newDate;
	BulkClub club;
	BasicMember     *bMember;
	PreferredMember *pMember;

	inFile.open("warehouseshoppers.txt");

	while(inFile)
	{
		getline(inFile, name);
		inFile >> membershipNum;
		inFile.ignore(1000, '\n');
		getline(inFile, memType);
		getline(inFile, month, '/');
		getline(inFile, day, '/');
		getline(inFile, year);
cout << "\nin function\nNAME: " << name << "something else";
		newDate = new Date(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()));

		if(memType == "Basic")
		{
			bMember = new BasicMember(name, membershipNum, memType, *newDate, 0.0);

			club.AddMember(bMember);
		}
		else
		{
			pMember = new PreferredMember(name, membershipNum, memType, *newDate, 0.0, 0.0);

			bMember = pMember;

			club.AddMember(bMember);
		}
	}

	inFile.close();

//	delete newDate;
//	delete bMember;
//	delete pMember;

	return club;
}



