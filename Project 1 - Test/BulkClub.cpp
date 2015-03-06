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
