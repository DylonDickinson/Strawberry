/*
 * PreferredMember.h
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#ifndef PREFERREDMEMBER_H_
#define PREFERREDMEMBER_H_

#ifndef REBATE_AMOUNT
#define REBATE_AMOUNT 8.5
#endif

#ifndef PREFERRED_DUES
#define PREFERRED_DUES 85.0
#endif

#include "BasicMember.h"

class PreferredMember: public BasicMember
{
public:
	PreferredMember();
	PreferredMember(string newName, long newMemNum, string newMemType,
					Date newExpDate, float newAmtSpent, float newRebate);
	virtual ~PreferredMember();

	void SetRebate(float newRebate);

	virtual void UpdateMember(Transaction updateTrans);

	float GetRebate() const;
	virtual bool DetermineStatus() const;
	virtual void PrintMember() const;

private:
	float rebate;
};

#endif /* PREFERREDMEMBER_H_ */
