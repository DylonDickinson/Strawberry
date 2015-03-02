/*
 * header.h
 *
 *  Created on: Feb 19, 2015
 *      Author: pwatson6
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <fstream>
#include "BulkClub.h"
#include "Transaction.h"
#include "BasicMember.h"
#include "PreferredMember.h"
using namespace std;

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

BulkClub ReadInMembers();

#endif /* HEADER_H_ */
