/*
 * header.h
 *
 *  Created on: Feb 19, 2015
 *      Author: pwatson6
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "BulkClub.h"
#include "Transaction.h"
#include "BasicMember.h"
#include "PreferredMember.h"
using namespace std;

#ifndef REBATE_AMOUNT
#define REBATE_AMOUNT 8.5
#endif

enum Menu
{
	SEARCH
};

enum SearchMenu
{
	SEARCH_NAME = 1,
	SEARCH_MEM_NUM = 2,
	SEARCH_DATE = 3,
	SEARCH_MONTH = 4

};

void ReadInMembers(BulkClub &dastrawburryclub);
void ReadInTransactions(BulkClub& dastrawburryclub);
void OneTransactionDate(ifstream &inFile, BulkClub &dastrawburryclub);

#endif /* HEADER_H_ */
