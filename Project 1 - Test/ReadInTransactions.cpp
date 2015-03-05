/*
 * ReadInTransactions.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Peter
 */

#include "header.h"
/*************************************************************************
* ReadInTransactions
* ________________________________________________________________________
* This function reads transaction information from multiple text files.
* ________________________________________________________________________
* PRE-CONDITIONS
*	strawberryClub : Contains an empty list of transactions
* POST-CONDITIONS
*	strawberryClud : Contains a list of transactions from an input file
**************************************************************************/
void ReadInTransactions(BulkClub& strawberryClub)
{
	ifstream inFileDay1;
	ifstream inFileDay2;
	ifstream inFileDay3;
	ifstream inFileDay4;
	ifstream inFileDay5;

	inFileDay1.open("day1.txt");
	inFileDay2.open("day2.txt");
	inFileDay3.open("day3.txt");
	inFileDay4.open("day4.txt");
	inFileDay5.open("day5.txt");

	OneTransactionDate(inFileDay1, strawberryClub);
	OneTransactionDate(inFileDay2, strawberryClub);
	OneTransactionDate(inFileDay3, strawberryClub);
	OneTransactionDate(inFileDay4, strawberryClub);
	OneTransactionDate(inFileDay5, strawberryClub);

	inFileDay1.close();
	inFileDay2.close();
	inFileDay3.close();
	inFileDay4.close();
	inFileDay5.close();
}


