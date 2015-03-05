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
	void SetMHead(BasicMember *newHead);
	void SetTHead(Transaction *newHead);

	// Accessors
	BasicMember* FindMember(long memberNum) const;
	void CompareExpDate(Date *datePtr) const;
	void OutputMembers() const;
	void OutputTransactions() const;
	Transaction* FindTransaction(Date searchDate) const;
	Transaction* FindTransaction(int searchId) const;
	Transaction* FindTransaction(string searchName) const;
	BasicMember* GetMHead() const;
	Transaction* GetTHead() const;

	//Output Reports
	void DaySalesReport(Date searchDay) const;
	void MemberSearch(string searchName) const;
	void MemberSearch(int searchId) const;
	void TotalPurchases() const;
	void ItemReport(string searchItemName) const;
	void TotalItemReport() const;
	void RebateReport() const;
	void DuesReport() const;
	void ExpDateReport(Date SearchMonth) const;
	void DetermineAccountStatus() const;

private:
	BasicMember *mHead;
	Transaction *transHead;
};


#endif /* BULKCLUB_H_ */
