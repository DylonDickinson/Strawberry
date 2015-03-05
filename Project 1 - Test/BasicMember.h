/*
 * BasicMember.h
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_

#ifndef TAX_AMOUNT
#define TAX_AMOUNT 8.75
#endif

#include "Date.h"
#include "Transaction.h"
#include <string>
using namespace std;

class BasicMember
{
public:
	BasicMember();
	BasicMember(string newName, long newMemNum, string newMemType,
				Date newExpDate, float newAmtSpent);
	virtual ~BasicMember();

	void SetName(string newName);
	void SetMemNum(long newMemNum);
	void SetMemTyp(string newMemType);
	void SetDate(Date newDate);
	void SetAmtSpent(float newAmtSpent);
	void AddAmtSpent(float addAmtSpent);
	void SetNext(BasicMember *nextMember);

	virtual void UpdateMember(Transaction updateTrans);

	string GetName() const;
	long GetMemNum() const;
	string GetMemType() const;
	Date GetExpDate() const;
	float GetAmtSpent() const;
	BasicMember* GetNext() const;
	virtual void PrintMember() const;

private:
	string name;
	long   memNum;
	string memType;
	Date   expDate;
	float  amtSpent;
	BasicMember *next;
};



#endif /* BASICMEMBER_H_ */
