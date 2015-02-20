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
	virtual ~PreferredMember();


private:
	int rebate;
};

#endif /* PREFERREDMEMBER_H_ */
