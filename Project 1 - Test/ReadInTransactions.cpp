/*
 * ReadInTransactions.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Peter
 */

#include "header.h"

void ReadInTransactions(BulkClub& dastrawburryclub)
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

	OneTransactionDate(inFileDay1, dastrawburryclub);
	OneTransactionDate(inFileDay2, dastrawburryclub);
	OneTransactionDate(inFileDay3, dastrawburryclub);
	OneTransactionDate(inFileDay4, dastrawburryclub);
	OneTransactionDate(inFileDay5, dastrawburryclub);

	inFileDay1.close();
	inFileDay2.close();
	inFileDay3.close();
	inFileDay4.close();
	inFileDay5.close();
}


