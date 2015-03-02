/*
 * PreferredMember.h
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#ifndef PREFERREDMEMBER_H_
#define PREFERREDMEMBER_H_

#include "BasicMember.h"

class PreferredMember: public BasicMember
{
public:
	PreferredMember();
	PreferredMember(string newName, long newMemNum, string newMemType,
					Date newExpDate, float newAmtSpent, float newRebate);
	virtual ~PreferredMember();

	void SetRebate(float newRebate);

	float GetRebate() const;
	virtual void PrintMember() const;

private:
	float rebate;
};

#endif /* PREFERREDMEMBER_H_ */
