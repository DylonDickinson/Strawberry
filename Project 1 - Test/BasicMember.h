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
   ~BasicMember();


private:
	string name;
	long   memNum;
	string memType;
	Date   expDate;
	float  amtSpent;

};



#endif /* BASICMEMBER_H_ */
