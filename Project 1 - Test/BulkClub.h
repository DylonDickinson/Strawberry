/*
 * BulkClub.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Alex
 */

#ifndef BULKCLUB_H_
#define BULKCLUB_H_

#include "PreferredMember.h"
#include "Transaction.h"

class BulkClub
{
public:
	BulkClub();
	~BulkClub();

	// Mutators
	void AddTransaction(Transaction *addTrans);
	void AddMember(BasicMember *newMember);
	bool RemoveMember(long memberNum);

	// Accessors
	BasicMember* FindMember(long memberNum) const;
	void OutputMembers() const;
	Transaction* FindTransaction(Date searchDate) const;
	Transaction* FindTransaction(int searchId) const;
	Transaction* FindTransaction(string searchName) const;

private:
	BasicMember *mHead;
	Transaction *transHead;
};


#endif /* BULKCLUB_H_ */
