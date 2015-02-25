/*
 * BasicMember.h
 *
 *  Created on: Feb 19, 2015
 *      Author: Alex
 */

#ifndef BASICMEMBER_H_
#define BASICMEMBER_H_

#include "Date.h"
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

	string GetName() const;
	long GetMemNum() const;
	string GetMemType() const;
	Date GetExpDate() const;
	float GetAmtSpent() const;
	virtual void PrintMember() const;

private:
	string name;
	long   memNum;
	string memType;
	Date   expDate;
	float  amtSpent;

};



#endif /* BASICMEMBER_H_ */
