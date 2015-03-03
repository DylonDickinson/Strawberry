/*
 * main.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: pwatson6
 */

#include "header.h"

int main()
{
	BulkClub daClub;

	ReadInMembers(daClub);
	ReadInTransactions(daClub);

	daClub.OutputMembers();
	daClub.OutputTransactions();

	return 0;
}


