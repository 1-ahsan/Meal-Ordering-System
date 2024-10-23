#pragma once
#include <iostream>
#include "Queue.h"
#include "Deal.h"
#include "LinkedList.h"
using namespace std;

class Order {
private:
	static int orderNo;
	int id;
	int customerId;
	float TotalPrice;
	LinkedList<Deal> deals;
	string status;
public:
	Order();
	Order(int id);
	Order(int customerid, LinkedList<Deal> deals,float price);
	void updateStatus();
	int getId();
	float getPrice();
	string getStatue();

	friend ostream& operator<<(std::ostream& os, const Order& order);
	bool operator==(const Order& other) const;
};