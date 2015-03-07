/*
 * OneTransactionDay.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Peter
 */

#include "header.h"
/*************************************************************************
* OneTransactionDay
* ________________________________________________________________________
* This function reads in a transaction of Transaction type and then adds
* 	it to the list in the BulkClub.
* ________________________________________________________________________
* PRE-CONDITIONS
*	strawberryClub : Contains an empty list of transactions
* POST-CONDITIONS
*	strawberryClud : Contains a list of transactions from one day from an
*					 input file
**************************************************************************/
void OneTransactionDate(ifstream &inFile, BulkClub &strawberryClub)
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

	BasicMember *memPtr;

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

		strawberryClub.AddTransaction(tPtr);

		memPtr = strawberryClub.FindMember(tPtr->GetId());

		memPtr->UpdateMember(*tPtr);
	}
}
