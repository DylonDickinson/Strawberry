/*
 * BulkClub.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Alex
 */

#ifndef BULKCLUB_H_
#define BULKCLUB_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include "PreferredMember.h"
#include "Transaction.h"
using namespace std;

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
	void TransactionsByName();
	void TransactionsById();

	//Output Reports that sort list
	string ItemReport();				// matt
	string DaySalesReport(Date *searchDay);  // Matt


	// Accessors
//	void SortMembersByNumber();
	BasicMember* FindMember(long memberNum) const;
	void OutputMembers() const;
	void OutputTransactions() const;
	Transaction* FindTransaction(Date searchDate) const;
	Transaction* FindTransaction(int searchId) const;
	Transaction* FindTransaction(string searchName) const;
	BasicMember* GetMHead() const;
	Transaction* GetTHead() const;

	//Output Reports that dont
	BasicMember* MemberSearch(string searchName) const;		//Alex
	BasicMember* MemberSearch(int searchId) const;			// Alex
	void TotalPurchases() const;					//Dylon
	void ItemReport(string searchItemName) const;	//Dylon
	void RebateReport() const;				//Peter - doneish
	void DuesReport() const; 				//Peter - doneish
	void OutputMembersWithExpDate(Date *datePtr) const; //Alex - doneish
	void DetermineAccountStatus() const;			//Peter

private:
	BasicMember *mHead;
	Transaction *transHead;
};


#endif /* BULKCLUB_H_ */
