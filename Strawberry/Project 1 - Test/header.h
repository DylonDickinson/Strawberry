/*
 * header.h
 *
 *  Created on: Feb 19, 2015
 *      Author: pwatson6
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <ios>
#include <limits>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
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
	SALES_REPORT = 10,
	SEARCH = 2,
	PRINT = 3,
	ADD_OR_DELETE = 4,
	EXIT = 0
};

enum SearchMenu
{
	NAME = 1,
	MEM_NUM = 2,
	MONTH = 3,
	ITEM = 4
};

enum PrintMenu
{
	TOTAL_PURCHASES = 1,
	ITEMS_SOLD = 2,
	AMT_PAID = 3
};

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
void ReadInMembers(BulkClub &strawberryClub);

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
void ReadInTransactions(BulkClub& strawberryClub);

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
void OneTransactionDate(ifstream &inFile, BulkClub &strawberryClub);

/*************************************************************************
* Boundary Check
* ________________________________________________________________________
* This function prompts the user for an integer and checks to make sure
* 	it is within the boundary values passed in.
* ________________________________________________________________________
* PRE-CONDITIONS
*	prompt   : The prompt for user to input integer.
*	maxValue : The max value that can be entered.
*	minValue : The minimum value that can be entered.
* POST-CONDITIONS
*	A valid input is returned to the calling function.
**************************************************************************/
int BoundaryCheck(string prompt,    // IN - The prompt for the input.
		 	 	  int    minValue,  // IN - The minimum possible value.
		 	 	  int    maxValue); // IN - The maximum possible value.

/*************************************************************************
* OutputErrorMessage
* ________________________________________________________________________
* This function calculates a setw for two lines of error messages and
* 	outputs the messages.
* ________________________________________________________________________
* PRE-CONDITIONS
*	value    : Value entered by user.
*	minValue : Minimum value user allowed to enter.
*	maxValue : Maximum value user allowed to enter.
* POST-CONDITIONS
*	<none>
*	Outputs the error message
**************************************************************************/
void OutputErrorMessage(int value,     // IN - Value inputted from user.
				  	    int minValue,  // IN - Max possible value entered.
				  	    int maxValue); // IN - Min possible value entered.

#endif /* HEADER_H_ */
