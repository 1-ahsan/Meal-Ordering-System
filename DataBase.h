#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Customer.h"
#include "Order.h"
#include "Deal.h"
#include "Admin.h"
#include "Queue.h"
#include "LinkedList.h"
using namespace std;

class DataBase {
private:
	static Admin admin;
	static Queue<Order> CompletedOrders;
	static Queue<Order> PendingOrders;
	static LinkedList<Customer> customers;
	static LinkedList<Deal> deals;
public:
    // Static methods to access and modify data
    static Admin& getAdmin();
    static Queue<Order>& getPendingOrders();
    static Queue<Order>& getCompletedOrders();
    static LinkedList<Customer>& getCustomers();
    static LinkedList<Deal>& getDeals();

    // Methods to add data
    static void addCustomer(const Customer& customer);
    static void addDeal(const Deal& deal);
    static void enqueuePendingOrder(const Order& order);
    static void enqueueCompletedOrder(const Order& order);
};
