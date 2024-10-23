#include <iostream>
#include <vector>
#include "DataBase.h"

using namespace std;

	// Member inilization 
Admin DataBase::admin("Ahsan", "123");
Queue<Order> DataBase::CompletedOrders;
Queue<Order> DataBase::PendingOrders;
LinkedList<Customer> DataBase::customers;
LinkedList<Deal> DataBase::deals;

Admin& DataBase::getAdmin() {
	return admin;
}
Queue<Order>& DataBase::getPendingOrders() {
    return PendingOrders;
}

Queue<Order>& DataBase::getCompletedOrders() {
    return CompletedOrders;
}

LinkedList<Customer>& DataBase::getCustomers() {
    return customers;
}

LinkedList<Deal>& DataBase::getDeals() {
    return deals;
}

void DataBase::addCustomer(const Customer& customer) {
    customers.insert(customer);
}

void DataBase::addDeal(const Deal& deal) {
    deals.insert(deal);
}

void DataBase::enqueuePendingOrder(const Order& order) {
    PendingOrders.Enqueue(order);
}

void DataBase::enqueueCompletedOrder(const Order& order) {
    CompletedOrders.Enqueue(order);
}