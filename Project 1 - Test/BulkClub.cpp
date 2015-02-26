/*
 * BulkClub.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Alex
 */

#include "BulkClub.h"

BulkClub::BulkClub()
{
	head = NULL;
	transHead = NULL;
}

BulkClub::~BulkClub()
{
	//Delete linked lists
}

void BulkClub::AddTransaction(Transaction *addTrans)
{
	if(transHead == NULL)
	{
		transHead = addTrans;
	}
	else
	{
		addTrans->SetNext(transHead);
		transHead = addTrans;
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
