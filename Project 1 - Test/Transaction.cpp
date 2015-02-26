/*
 * Transaction.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: Peter
 */

#include "Transaction.h"

	Transaction::Transaction()
	{
		transDate.SetDate(0,0,0);
		id = 0;
		itemName = "";
		price = 0.0;
		amount = 0;
	}
	Transaction::Transaction(Date newTransDate,
							 int newId,
							 string newItemName,
							 float newItemPrice,
							 int newAmount)
	{
		SetTransDate(newTransDate);
		SetId(newId);
		SetName(newItemName);
		SetPrice(newItemPrice);
		SetAmount(newAmount);
	}
	Transaction::~Transaction() {}

	void Transaction::SetTransDate(Date newTransDate) {}
	void Transaction::SetId(int newId) {}
	void Transaction::SetName(string newItemName) {}
	void Transaction::SetPrice(float newPrice) {}
	void Transaction::SetAmount(int newAmount) {}
	void Transaction::RemoveAmount(int removeAmount) {}
	void Transaction::AddAmount(int addAmount) {}

	Date Transaction::GetTransDate() const {}
	int Transaction::GetId() const {}
	string Transaction::GetName() const {}
	float Transaction::GetPrice() const {}
	int Transaction::GetAmount() const {}
	void Transaction::PrintTrans() const {}
