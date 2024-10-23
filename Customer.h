#pragma once
#include <iostream>
#include <string>
#include "Queue.h"
#include "User.h"
#include "Order.h"
using namespace std;

class Customer :public User {
private:
	string phoneNumber;
	int id;
	string address;
	LinkedList<Deal> cart;
	LinkedList<Order> orderHistory;

public:
	Customer(int id);
	Customer(const string username, int id, const string password, const string address, const string phoneNumber);
	bool Login(string name, string pass) const;
	void ChangePasseord();
	int getId() const;

	void ViewDeals();
	void AddDealsInOrder();
	void TrackYourOrder();

	bool operator==(const Customer& other) const; // Comparison operators for LinkedList
	bool operator!=(const Customer& other) const; 
};