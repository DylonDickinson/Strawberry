/*
 * OneTransactionDay.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Peter
 */

#include "header.h"

void OneTransactionDate(ifstream &inFile, BulkClub &dastrawburryclub)
{
	string month;
	string day;
	string year;
	string itemName;
	int memberNum;
	float itemPrice;
	int itemAmount;
	Date *newDate;
	Transaction *tPtr;

	while(!inFile.eof())
	{
		getline(inFile, month, '/');
		getline(inFile, day, '/');
		getline(inFile, year);
		newDate = new Date(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()));
		inFile >> memberNum;
		inFile.ignore(10000, '\n');
		getline(inFile, itemName);
		inFile >> itemPrice;
		inFile >> itemAmount;
		inFile.ignore(10000, '\n');

		tPtr = new Transaction(*newDate, memberNum, itemName, itemPrice, itemAmount);

		dastrawburryclub.AddTransaction(tPtr);
	}
}
