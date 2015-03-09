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
	const string MAIN_MENU = "Main Menu\n"
							 "1 - Search for something\n"
							 "2 - Print a Report\n"
							 "3 - Add or Delete a Member\n"
							 "Enter a command: ";

	const string SEARCH_MENU = "What would you like to search for?\n"
							   "1 - Purchases by Member Name\n"
							   "2 - Purchases by Member Number\n"
							   "3 - Membership Expiration by Month\n"
							   "Enter a command: ";

	const string PRINT_MENU = "Print Menu\n"
							  "What would you like to print?\n"
							  "1 - Total Purchases\n"
							  "2 - Quantity and price of item sold\n"
							  "3 - "
							  "Enter a command: ";

	BulkClub daClub;
	Date *datePtr;
	string itemSearch;
	short yearExp, monthExp;
	short command1, commandSearch, commandPrint, dayPrintReport, addOrDeleteCommand;

	ReadInMembers(daClub);
	ReadInTransactions(daClub);

	command1 = BoundaryCheck(MAIN_MENU, 0, 3);

	while(command1 != EXIT || commandSearch != EXIT
		  || commandPrint != EXIT || dayPrintReport != EXIT)
	{
		switch(command1)
		{
		case SEARCH : commandSearch = BoundaryCheck(SEARCH_MENU, 0, 4);

						switch(commandSearch)
						{
						case NAME : cout << "\nOutput purchases made by members with name entered\n";
									// (2) output purchases
							break;

						case MEM_NUM : cout << "\nOutput purchases made by members with ID entered\n";
										// (2) output purchases
							break;

						case MONTH : monthExp = BoundaryCheck("Which month would you like to search for? (1-12) ", 1, 12);
									 yearExp  = BoundaryCheck("Which year would you like to search for? ", 2000, 2020);

									 datePtr = new Date(monthExp, 1, yearExp);

									 cout << "The list of memberships that expire on " << monthExp << '/' << yearExp << endl;
									 daClub.OutputMembersWithExpDate(datePtr);

									 delete datePtr;

							break;

						case ITEM : /*cout << "Which item would you like to search for? ";
									getline(cin, itemSearch);*/
									cout << "\nOutput quantity and sales price of item entered\n";
									// (4)
							break;
						}
			break;

		case PRINT : commandPrint = BoundaryCheck(PRINT_MENU, 0, 3);

						switch(commandPrint)
						{
						case SALES_REPORT : dayPrintReport /*(1)*/
											= BoundaryCheck("Which day would you like a report for? ",
															1, 5);
											datePtr = new Date(2, dayPrintReport, 2015);
											cout << daClub.DaySalesReport(datePtr);
							break;

						case TOTAL_PURCHASES : cout << "\nOuputs all purchases made by members sorted by membership number\n";
											// (3) all purchases sorted by mem number
							break;

						case ITEMS_SOLD : cout << daClub.ItemReport();
											// (5) items sold with total sales price
							break;

						case AMT_PAID : cout << "\nOutputs amount paid by each member\n";
										// (7) amt paid per year per member
							break;
						}
			break;

		case ADD_OR_DELETE : cout << "\nMenu to add or delete member and will get necessary information\n";
	//						switch(addOrDeleteCommand)
	//						{
	//						case ADD :
	//							break;
	//						case DELETE :
	//							break;
	//						}
			break;
		}
	}


	return 0;
}


