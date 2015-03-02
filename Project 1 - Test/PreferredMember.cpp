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
	SetRebate(rebate);
}
PreferredMember::~PreferredMember(){}

void PreferredMember::SetRebate(float newRebate)
{
	rebate = newRebate;
}

float PreferredMember::GetRebate() const
{
	return rebate;
}
void PreferredMember::PrintMember() const
{
	BasicMember::PrintMember();
	cout << "Rebate: " << rebate;
}
