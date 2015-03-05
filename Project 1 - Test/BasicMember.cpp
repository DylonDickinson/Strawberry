/*
 * BasicMember.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#include "BasicMember.h"

BasicMember::BasicMember()
{
	name = "";
	memNum = 0;
	memType = "";
	expDate.SetDate(0,0,0);
	amtSpent = 0.0;
	next = NULL;
}
BasicMember::BasicMember(string newName, long newMemNum, string newMemType,
			Date newExpDate, float newAmtSpent)
{
	SetName(newName);
	SetMemNum(newMemNum);
	SetMemTyp(newMemType);
	SetDate(newExpDate);
	SetAmtSpent(newAmtSpent);
}
BasicMember::~BasicMember() {}

void BasicMember::SetName(string newName)
{
	name = newName;
}
void BasicMember::SetMemNum(long newMemNum)
{
	memNum = newMemNum;
}
void BasicMember::SetMemTyp(string newMemType)
{
	memType = newMemType;
}
void BasicMember::SetDate(Date newDate)
{
	expDate = newDate;
}
void BasicMember::SetAmtSpent(float newAmtSpent)
{
	amtSpent = newAmtSpent;
}
void BasicMember::AddAmtSpent(float addAmtSpent)
{
	amtSpent += addAmtSpent;
}
void BasicMember::SetNext(BasicMember *nextMember)
{
	next = nextMember;
}

void BasicMember::UpdateMember(Transaction updateTrans)
{
	float amountSpent;

	amountSpent = ((updateTrans.GetAmount() * updateTrans.GetPrice()) * (1 + TAX_AMOUNT));

	AddAmtSpent(amountSpent);
}


string BasicMember::GetName() const
{
	return name;
}
long BasicMember::GetMemNum() const
{
	return memNum;
}
string BasicMember::GetMemType() const
{
	return memType;
}
Date BasicMember::GetExpDate() const
{
	return expDate;
}
float BasicMember::GetAmtSpent() const
{
	return amtSpent;
}
BasicMember* BasicMember::GetNext() const
{
	return next;
}
void BasicMember::PrintMember() const
{
	cout << "Name: " << name << endl;
	cout << "Member Number: " << memNum << endl;
	cout << "Member Type: " << memType << endl;
	cout << "Expiration Date: " << expDate.DisplayDate() << endl;
	cout << "Amount Spent: " << amtSpent << endl;
}


