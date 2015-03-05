/*************************************************************************
 * AUTHOR 	     : Alex Arrieta
 * ASSIGNMENT #1
 * CLASS         : CS1C
 * SECTION       : TTh 12:30 - 1:50
 * DUE DATE      : 1/27/15
 *************************************************************************/
#include "header.h"

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
int BoundaryCheck(string prompt,   // IN - The prompt for the input.
		 	 	  int    minValue, // IN - The minimum possible value.
		 	 	  int    maxValue) // IN - The maximum possible value.
{
	int validInput; // IN & CALC - Integer input that checked and returned
					//		       when valid.
	bool invalid;   // CALC      - Causes a loop when invalid input is
					//			   entered.

	invalid = false;

	// DO WHILE - Prompts user for integer input and error checks for char and
	// 		      boundary values.
	do
	{
		cout << prompt;

		if(!(cin  >> validInput))
		{
			cout << "\n**** Please input a NUMBER between " << minValue
				 << " and " << maxValue << " ****\n\n";
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			invalid = true;

		}
		else if((validInput < minValue) || (validInput > maxValue))
		{
			OutputErrorMessage(validInput, minValue, maxValue);
			invalid = true;
		}
		else
		{
			invalid = false;
		}

	}while(invalid);

	cin.ignore(1000, '\n');
	cout << endl;

	return validInput;
}
