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
		next = NULL;
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
		next = NULL;
	}
	Transaction::~Transaction() {}

	void Transaction::SetTransDate(Date newTransDate)
	{
		transDate = newTransDate;
	}
	void Transaction::SetId(int newId)
	{
		id = newId;
	}
	void Transaction::SetName(string newItemName)
	{
		itemName = newItemName;
	}
	void Transaction::SetPrice(float newPrice)
	{
		price = newPrice;
	}
	void Transaction::SetAmount(int newAmount)
	{
		amount = newAmount;
	}
	void Transaction::SetNext(Transaction *transLink)
	{
		next = transLink;
	}
	void Transaction::RemoveAmount(int removeAmount)
	{
		amount -= removeAmount;
	}
	void Transaction::AddAmount(int addAmount)
	{
		amount += addAmount;
	}

	Date Transaction::GetTransDate() const
	{
		return transDate;
	}
	int Transaction::GetId() const
	{
		return id;
	}
	string Transaction::GetName() const
	{
		return itemName;
	}
	float Transaction::GetPrice() const
	{
		return price;
	}
	int Transaction::GetAmount() const
	{
		return amount;
	}
	Transaction* Transaction::GetNext() const
	{
		return next;
	}
	void Transaction::PrintTrans() const
	{
		cout << "Transaction Date: " << transDate.DisplayDate() << endl;
		cout << "User ID: " << id << endl;
		cout << "Item Name: " << itemName << endl;
		cout << "Item Prie: " << price << endl;
		cout << "Item Amount: " << amount << endl;
	}
