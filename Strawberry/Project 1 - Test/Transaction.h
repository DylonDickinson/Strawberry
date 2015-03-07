/*
 * Transaction.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Peter
 */

#include "Date.h"
using namespace std;
#include <iostream>
#include <string>

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

class Transaction
{
	public:
	Transaction();
	Transaction(Date newTransDate,
				int newId,
				string newItemName,
				float newItemPrice,
				int newAmount);
	~Transaction();

	void SetTransDate(Date newTransDate);
	void SetId(int newId);
	void SetName(string newItemName);
	void SetPrice(float newPrice);
	void SetAmount(int newAmount);
	void SetNext(Transaction *transLink);
	void RemoveAmount(int removeAmount);
	void AddAmount(int addAmount);

	Date GetTransDate() const;
	int GetId() const;
	string GetName() const;
	float GetPrice() const;
	int GetAmount() const;
	Transaction *GetNext() const;
	void PrintTrans() const;

	private:
		Date transDate;
		int id;
		string itemName;
		float price;
		int amount;
		Transaction *next;
};

#endif /* TRANSACTION_H_ */
