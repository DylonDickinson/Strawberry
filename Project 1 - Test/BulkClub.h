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
//	void SortMembersByNumber();
//	void TransacionsByDate();
	BasicMember* FindMember(long memberNum) const;
	void OutputMembers() const;
	void OutputTransactions() const;
	Transaction* FindTransaction(Date searchDate) const;
	Transaction* FindTransaction(int searchId) const;
	Transaction* FindTransaction(string searchName) const;
	BasicMember* GetMHead() const;
	Transaction* GetTHead() const;

	//Output Reports
<<<<<<< HEAD


	string DaySalesReport(Date searchDay) const;  // Matt
	BasicMember* MemberSearch(string searchName) const;		//Alex
	BasicMember* MemberSearch(int searchId) const;			// Alex
	void TotalPurchases() const;					//Dylon
	void ItemReport(string searchItemName) const;	//Dylon
	void TotalItemReport() const;				//Matt
	void RebateReport() const;				//Peter - doneish
	void DuesReport() const; 				//Peter - doneish
	void OutputMembersWithExpDate(Date *datePtr) const; //Alex - doneish
	void DetermineAccountStatus() const;			//Peter
=======
//<<<<<<< HEAD
	string DaySalesReport(Date searchDay) const;
	void MemberSearch(string searchName) const;
	BasicMember* MemberSearch(int searchId) const;
	void TotalPurchases() const;
	string ItemReport() const;
	void TotalItemReport() const;
	void RebateReport() const;
	void OutputMembersWithExpDate(Date *datePtr) const;
	void ExpDateReport(Date SearchMonth) const;
	void DetermineAccountStatus() const;

//=======
//	void DaySalesReport(Date searchDay) const;  // Matt
//	void MemberSearch(string searchName) const;		//Alex
//	void MemberSearch(int searchId) const;			// Alex
//	void TotalPurchases() const;					//Dylon
//	void ItemReport(string searchItemName) const;	//Dylon
//	void TotalItemReport() const;				//Matt
//	void RebateReport() const;				//Peter
//	void OutputMembersWithExpDate(Date *datePtr) const; //Alex
//	void ExpDateReport(Date SearchMonth) const;		//Peter
//	void DetermineAccountStatus() const;			//Peter
//>>>>>>> master
>>>>>>> mattBranch

private:
	BasicMember *mHead;
	Transaction *transHead;
};


#endif /* BULKCLUB_H_ */
