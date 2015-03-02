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


	daClub = ReadInMembers();

	daClub.OutputMembers();

	return 0;
}


