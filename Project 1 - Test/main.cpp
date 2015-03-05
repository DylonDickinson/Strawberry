/*************************************************************************
 * AUTHORS 	     : Alex Arrieta, Peter Watson,
 * 				   Matt Corrente, Dylon Dickonson
 * CLASS PROJECT
 * CLASS         : CS1C
 * DUE DATE      : 3/16/15
 *************************************************************************/
#include "header.h"

int main()
{
	const string MAIN_MENU = "1 - Search for something\n"
							 "2 - Print a Report\n"
							 "3 - Add or Delete a Member\n"
							 "Enter a command: ";

	const string SEARCH_MENU = "What would you like to search for?\n"
							   "1 - Purchases by Member Name\n"
							   "2 - Purchases by Member Number\n"
							   "3 - Membership Expiration by Month\n"
							   "Enter a command: ";
	const string PRINT_MENU = "What would you like to print?\n"
							  "1 - Total Purchases\n"
							  "2 - Quantity and price of item sold\n"
							  "3 - "
							  "Enter a command: ";


	BulkClub daClub;
//	short    command1, commandSearch, commandPrint, dayPrintReport;

	ReadInMembers(daClub);
	ReadInTransactions(daClub);

//	BoundaryCheck(MAIN_MENU, 0, 2);
//
//	switch(command1)
//	{
//	case SEARCH : commandSearch = BoundaryCheck(SEARCH_MENU, 0, 4);
//					switch(commandSearch)
//					{
//					case NAME : // (2) output purchases
//						break;
//					case MEM_NUM : // (2) output purchases
//						break;
//					case MONTH : // (8) members exp date by month
//						break;
//					case ITEM : // (4) quantity and price of item
//						break;
//					}
//		break;
//
//	case PRINT : commandPrint = BoundaryCheck(PRINT_MENU, 0, 3);
//					switch(commandPrint)
//					{
//					case SALES_REPORT : dayPrintReport = BoundaryCheck("Which day would you like a report for? ", 1, 5);
//										// (1)
//						break;
//					case TOTAL_PURCHASES : // (3) all purchases sorted by mem number
//						break;
//					case ITEMS_SOLD : // (5) items sold with total sales price
//						break;
//					case AMT_PAID : // (7) amt paid per year per member
//						break;
//					}
//		break;
//	case ADD_OR_DELETE : // Add or delete member
//		break;
//
//	}

	daClub.OutputMembers();
	daClub.OutputTransactions();

	return 0;
}


