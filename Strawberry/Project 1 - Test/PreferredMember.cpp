/*
 * PreferredMember.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#include "PreferredMember.h"

PreferredMember::PreferredMember()
{
	rebate = 0.0;
}
PreferredMember::PreferredMember(string newName, long newMemNum, string newMemType,
								 Date newExpDate, float newAmtSpent, float newRebate)
:BasicMember(newName, newMemNum, newMemType, newExpDate, newAmtSpent)
{
	SetRebate(newRebate);
}
PreferredMember::~PreferredMember(){}

void PreferredMember::SetRebate(float newRebate)
{
	rebate = newRebate;
}

void PreferredMember::UpdateMember(Transaction updateTrans)
{
	float amountSpent;
	float totalAmountSpent;

	amountSpent = (updateTrans.GetAmount() * updateTrans.GetPrice());
	totalAmountSpent = amountSpent;
	//I DONT FUCKING KNOW IF WE NEED TO DO THIS
	// totalAmountSpent = ((amountSpent - (REBATE_AMOUNT * amountSpent)) * (1 + TAX_AMOUNT))

	AddAmtSpent(totalAmountSpent);
}

float PreferredMember::GetRebate() const
{
	return rebate;
}
void PreferredMember::PrintMember() const
{
	BasicMember::PrintMember();
	cout << "Rebate: " << rebate << endl;
}
