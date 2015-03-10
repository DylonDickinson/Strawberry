/*
 * BulkClub.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Alex
 */

#include "BulkClub.h"

BulkClub::BulkClub()
{
	mHead = NULL;
	transHead = NULL;
}

BulkClub::~BulkClub()
{
	BasicMember *ptrOne;
	BasicMember *ptrTwo;

	ptrOne = mHead;

	while(ptrOne != NULL)
	{
		ptrTwo = ptrOne;
		ptrOne = ptrTwo->GetNext();
		delete ptrTwo;
	}
}

void BulkClub::AddMember(BasicMember *newMember)
{
	BasicMember *mPtr;
	mPtr = mHead;

	bool added = false;

	if(mPtr == NULL)
	{
		newMember->SetNext(mHead);
		mHead = newMember;
		added = true;
	}
	else if(mPtr->GetMemNum() > newMember->GetMemNum())
	{
		newMember->SetNext(mPtr);
		mHead = newMember;
		added = true;
	}
	else
	{
		while(mPtr->GetNext() != NULL && !added)
		{
			if(mPtr->GetNext()->GetMemNum() > newMember->GetMemNum())
			{
				newMember->SetNext(mPtr->GetNext());
				mPtr->SetNext(newMember);
				added = true;
			}
			else
			{
				mPtr = mPtr->GetNext();
			}
		}

		if(mPtr->GetNext() == NULL)
		{
			newMember->SetNext(mPtr->GetNext());
			mPtr->SetNext(newMember);
			added = true;
		}
	}
}

bool BulkClub::RemoveMember(long memberNum)
{
	BasicMember* member;
	BasicMember* auxPtr;
	bool found = false;

	member = mHead;
	if(member == NULL)
	{
		cout << "**** Cannot remove from an empty list. ****\n";
	}
	else if(member->GetMemNum() == memberNum)
	{
		mHead = member->GetNext();
		delete member;
		member = mHead;
		found = true;
	}
	else
	{

		while((member->GetNext() != NULL) && !found)
		{

			if(member->GetNext()->GetMemNum() == memberNum)
			{
				found = true;
				auxPtr = member->GetNext();
				member->SetNext(member->GetNext()->GetNext());
				delete auxPtr;
			}
			else
			{
				member = member->GetNext();
			}

		}

	}
	return found;
}

void BulkClub::AddTransaction(Transaction *addTrans)
{
	Transaction *tPtr;

	tPtr = transHead;

	if(transHead == NULL)
	{
		addTrans->SetNext(transHead);
		transHead = addTrans;
	}
	else
	{
		while(tPtr->GetNext() != NULL)
		{
			tPtr = tPtr->GetNext();
		}
		addTrans->SetNext(tPtr->GetNext());
		tPtr->SetNext(addTrans);
	}
}

void BulkClub::SetMHead(BasicMember *newHead)
{
	mHead = newHead;
}
void BulkClub::SetTHead(Transaction *newHead)
{
	transHead = newHead;
}

void BulkClub::TransactionsByName()
{
	Transaction* temp = transHead;

	Date transDate;
	int id;
	string itemName;
	float price;
	int amount;

	int counter = 0;

	while(temp != NULL)
	{
		temp = temp->GetNext();
		counter++;
	}

	temp = transHead;
	for(int i = 0; i < counter; i++)
	{
		while(temp->GetNext() != NULL)
		{
			if(temp->GetName() > temp->GetNext()->GetName())
			{
				transDate = temp->GetTransDate();
				temp->SetTransDate(temp->GetNext()->GetTransDate());
				temp->GetNext()->SetTransDate(transDate);

				id = temp->GetId();
				temp->SetId(temp->GetNext()->GetId());
				temp->GetNext()->SetId(id);

				itemName = temp->GetName();
				temp->SetName(temp->GetNext()->GetName());
				temp->GetNext()->SetName(itemName);

				price = temp->GetPrice();
				temp->SetPrice(temp->GetNext()->GetPrice());
				temp->GetNext()->SetPrice(price);

				amount = temp->GetAmount();
				temp->SetAmount(temp->GetNext()->GetAmount());
				temp->GetNext()->SetAmount(amount);
			}
			temp = temp->GetNext();
		}
		temp = transHead;
	}
}

void BulkClub::TransactionsById()
{
	Transaction* temp = transHead;

	Date transDate;
	int id;
	string itemName;
	float price;
	int amount;

	int counter = 0;

	while(temp != NULL)
	{
		temp = temp->GetNext();
		counter++;
	}

	temp = transHead;
	for(int i = 0; i < counter; i++)
	{
		while(temp->GetNext() != NULL)
		{
			if(temp->GetId() > temp->GetNext()->GetId())
			{
				transDate = temp->GetTransDate();
				temp->SetTransDate(temp->GetNext()->GetTransDate());
				temp->GetNext()->SetTransDate(transDate);

				id = temp->GetId();
				temp->SetId(temp->GetNext()->GetId());
				temp->GetNext()->SetId(id);

				itemName = temp->GetName();
				temp->SetName(temp->GetNext()->GetName());
				temp->GetNext()->SetName(itemName);

				price = temp->GetPrice();
				temp->SetPrice(temp->GetNext()->GetPrice());
				temp->GetNext()->SetPrice(price);

				amount = temp->GetAmount();
				temp->SetAmount(temp->GetNext()->GetAmount());
				temp->GetNext()->SetAmount(amount);
			}
			temp = temp->GetNext();
		}
		temp = transHead;
	}
}

string BulkClub::ItemReport()
{
	Transaction *auxPtr;
	auxPtr = transHead;
	ostringstream output;
	int count;

	TransactionsByName();

	while(auxPtr != NULL)
	{

		output << "Item: " << auxPtr->GetName() << endl;
		count = auxPtr->GetAmount();

		if(auxPtr->GetNext() != NULL)
		{
			while(auxPtr->GetName() == auxPtr->GetNext()->GetName())
			{
				auxPtr = auxPtr->GetNext();
				count += auxPtr->GetAmount();
			}
		}

		output << "Quantity: " << count << endl;

		count = 0;

		auxPtr = auxPtr->GetNext();
	}
	return output.str();
}

BasicMember* BulkClub::FindMember(long memberNum) const
{
	BasicMember *member;

	bool found = false;
	member = mHead;

	if(member != NULL)
	{

			while((member->GetNext() != NULL) && !found)
			{

				if(member->GetMemNum() == memberNum)
				{
					found = true;
				}
				else
				{
					member = member->GetNext();
				}

			}

	 }

	 return member;
}

void BulkClub::OutputMembers() const
{
	BasicMember *memPtr;

	memPtr = mHead;

	while(memPtr != NULL)
	{
		memPtr->PrintMember();
		memPtr = memPtr->GetNext();
		cout << endl;
	}
}

void BulkClub::OutputTransactions() const
{
	Transaction *tPtr;
	tPtr = transHead;

	while(tPtr != NULL)
	{
		tPtr->PrintTrans();
		tPtr = tPtr->GetNext();
		cout << endl;
	}
}

Transaction* BulkClub::FindTransaction(Date searchDate) const
{
	Transaction *searchPtr = transHead;
	bool notFound = true;
	while (notFound && transHead != NULL)
	{
		if(searchPtr->GetTransDate().CompareDate(searchDate))
		{
			notFound = false;
		}
		else
		{
			searchPtr = searchPtr->GetNext();
		}
	}

	return searchPtr;
}
Transaction* BulkClub::FindTransaction(int searchId) const
{
	Transaction *searchPtr = transHead;
	bool notFound = true;
	while (notFound && transHead != NULL)
	{
		if(searchPtr->GetId() == searchId)
		{
			notFound = false;
		}
		else
		{
			searchPtr = searchPtr->GetNext();
		}
	}

	return searchPtr;
}
Transaction* BulkClub::FindTransaction(string searchName) const
{
	Transaction *searchPtr = transHead;
	bool notFound = true;
	while (notFound && transHead != NULL)
	{
		if(searchPtr->GetName() == searchName)
		{
			notFound = false;
		}
		else
		{
			searchPtr = searchPtr->GetNext();
		}
	}

	return searchPtr;
}


BasicMember* BulkClub::GetMHead() const
{
	return mHead;
}
Transaction* BulkClub::GetTHead() const
{
	return transHead;
}


// Will need to have member list sorted by member number first.
void BulkClub::RebateReport() const				//Peter
{
	BasicMember *loopPtr;
	loopPtr = mHead;
	while(loopPtr != NULL)
	{
		if(loopPtr->GetMemType() == "Preferred")
		{
			loopPtr->PrintMember();
		}

		loopPtr = loopPtr->GetNext();
	}
}

// WILL ONLY WORK IF MEMBER LIST IS SORTED BY NAME
void BulkClub::DuesReport() const
{
	BasicMember *memPtr;
	memPtr = mHead;

	while(memPtr != NULL)
	{
		if(memPtr->GetMemType() == "Basic")
		{
			memPtr->PrintMember();
		}

		memPtr = memPtr->GetNext();
	}

	memPtr = mHead;

	while(memPtr != NULL)
	{
		if(memPtr->GetMemType() == "Preferred")
		{
			memPtr->PrintMember();
		}

		memPtr = memPtr->GetNext();
	}
}

void BulkClub::OutputMembersWithExpDate(Date *datePtr) const
{
	BasicMember *memPtr;

	memPtr = mHead;

	while(memPtr != NULL)
	{
		if((memPtr->GetExpDate().GetMonth() == datePtr->GetMonth()) &&
		   (memPtr->GetExpDate().GetYear() == datePtr->GetYear()))
		{
			cout << "Name: " << memPtr->GetName() << endl;
			cout << "Amount Due: " << memPtr->GetAmtSpent() << endl;
		}

		memPtr = memPtr->GetNext();
	}

}

string BulkClub::DaySalesReport(Date *searchDay) const
{
	Transaction *tranPtr = transHead; //PROC - used to traverse transaction list
	BasicMember *memPtr;	//PROC - used to create customer list
	BasicMember *searchPtr; //PROC - used to traverse customer list
	BasicMember *head;      //PROC - head of customer list
	ostringstream itemList; //OUT  - ostring for item/quantity report
	ostringstream membersWhoShopped; //PROC - ostring for customer report
	float totalRev = 0; //PROC - daily total revenue
	int preferredMem = 0; //PROC - preferred member count
	int basicMem = 0;   //PROC - basic member count
	int myMemNum;   //PROC - used to find customer info corresponding with this id
	bool found;     //PROC - used to check if customers were found
	ostringstream output; //Used to store entire sales report to be returned as a string


	itemList << left;
	membersWhoShopped << left;

	head = NULL;

	//Format the list headings for todays item/quantity and members who shopped report
	itemList << setw(30) << "Items Sold" << "Quantity Sold" << endl;
	itemList << setfill('*');

	itemList << setfill('*');
	itemList << setw(29) << '*' << setw(14) << ' ' << endl;
	itemList << setfill(' ');

	membersWhoShopped << "Members Who Shopped" << endl;
	membersWhoShopped << setfill('*');
	membersWhoShopped << setw(19) << '*' << endl;
	membersWhoShopped << setfill(' ');

	memPtr = new BasicMember;

	//Begin while loop to traverse through transactions until end of list is reached
	while (tranPtr->GetNext() != NULL)
	{
		//If transaction matches date, then process infor for that day
		if(tranPtr->GetTransDate().CompareDate(*searchDay))
		{
			//OUTPUT - item name to item list
			itemList << setw(30) << tranPtr->GetName();
			itemList << tranPtr->GetAmount() << endl;

			//CALC - total amount spent on item and add it to total cost
			totalRev+=(tranPtr->GetAmount()*tranPtr->GetPrice());

			//PROC - copy member info corresponding to the member who performed transaction
			//		 into a a new node
			myMemNum = tranPtr->GetId();
			memPtr->CopyMember(MemberSearch(myMemNum));

			//If the head of our BasicMember list is empty, then add customer
			if(head == NULL)
			{
				memPtr->SetNext(head);
				head = memPtr;

				memPtr = new BasicMember;
			}
			//IF list is not empty perform checks to see if customer is allready
			//   on the list
			else
			{
				searchPtr = head;
				found = false;

				//If there is one customer on the list
				if(searchPtr->GetNext() == NULL)
				{
					//If the customer to be added differs from the one
					//   on the list then add to list
					if(searchPtr->GetMemNum() != myMemNum)
					{
					memPtr->SetNext(head);
					head = memPtr;
					memPtr = new BasicMember;
					}
				}
				//IF not they perform search to traverse list of customers
				else
				{
							while(searchPtr->GetNext() != NULL && !found)
							{
								if(searchPtr->GetMemNum() == myMemNum)
								{
									found = true;
								}
								else
								{
									searchPtr = searchPtr->GetNext();
								}
							} //end while searchPtr->GetNext()!=NULL

							//If member # not found on list then they need to be added to list of todays shoppers
							if(!found)
							{
								memPtr->SetNext(head);
								head = memPtr;
								memPtr = new BasicMember;
							}//end if(!found)
				}//end else

			}//end else

		}//end if transaction matches search for date

	  tranPtr = tranPtr->GetNext();

	}//end while traversing through transaction list

	searchPtr = head;

	//IF there is at least one shopper on the list then a sales report will be generated
	if(searchPtr != NULL)
	{
		//BEGIN while to process and output the customers who shopped
		//	on the searched for date to the membersWhoShopped ostring
		//	while also deleting every node from the list
		while(searchPtr->GetNext() != NULL)
		{
			membersWhoShopped << searchPtr->GetName() << endl;
			//PROC - increment either basic or preferred member count
			if(searchPtr->GetMemType() == "Basic")
				{
					basicMem++;
				}
				else
				{
					preferredMem++;
				}

			head = searchPtr->GetNext();

			delete searchPtr;
			searchPtr = head;
		}
		//OUTPUT - store all data into one ostring variable to be returned
		output << "Sales report for " << searchDay->DisplayDate() <<':' << endl << endl;
		output << itemList.str() << endl;
		output << "Total revenue for today $" << setprecision(2) << fixed << totalRev << endl << endl;
		output << membersWhoShopped.str() << endl;
		output << "Number of basic members who shopped today: " << basicMem << endl;
		output << "Number of preferred members who shopped today: " << preferredMem << endl;
    }//end if (searchPtr != NULL)
	//ELSE no sales report is necessary because no transactions exist on search for date
	else
	{
		output << "\nNo transactions were made on " << searchDay->DisplayDate() << endl << endl;
	}

	output << setprecision(6);
	itemList << right;
	membersWhoShopped << right;
	delete searchPtr;
	delete tranPtr;
	delete  memPtr;

	return output.str();
}

BasicMember* BulkClub::MemberSearch(int searchId) const
{
	BasicMember *searchPtr = mHead;
	bool found = false;
	while (searchPtr != NULL && !found)
	{
		if(searchPtr->GetMemNum() == searchId)
		{
			found = true;
		}
		else
		{
			searchPtr = searchPtr->GetNext();
		}
	}

	return searchPtr;
}

BasicMember *BulkClub::MemberSearch(string searchName) const
{
	BasicMember *searchPtr = mHead;
	bool found = false;
	while (searchPtr != NULL && !found)
	{
		if(searchPtr->GetName() == searchName)
		{
			found = true;
		}
		else
		{
			searchPtr = searchPtr->GetNext();
		}
	}

	return searchPtr;
}

void BulkClub::DetermineAccountStatus() const			//Peter
{
	BasicMember *auxPtr = mHead;
	ostringstream basicMembers;
	ostringstream prefMembers;
	while(auxPtr != NULL)
	{
		if(auxPtr->GetMemType() == "Basic")
		{
			if(auxPtr->DetermineStatus())
			{
				basicMembers << auxPtr->GetName() << endl;
			}
		}
		else if(auxPtr->GetMemType() == "Preferred")
		{
			if(auxPtr->DetermineStatus())
			{
				prefMembers << auxPtr->GetName() << endl;
			}
		}
	}

	cout << "These Basic members would save money if they upgraded to\n"
			"Preferred status and continued spending the on average the"
			"Same amount of money per month at the Bulk Club:\n\n";
	cout << basicMembers.str() << endl;


	cout << "These Preferred members would save money if they downgraded\n"
			"To Basic status:\n\n";
	cout << prefMembers.str() << endl;
}
