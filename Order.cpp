#include <iostream>
#include "Order.h"
#include "Queue.h"
#include "Deal.h"
#include "LinkedList.h"
using namespace std;

int Order::orderNo = 0;

Order::Order() {
	id = orderNo;
	TotalPrice = 1;
    status = "Pending";
}
Order::Order(int id) {
    this->id = id;
}
Order::Order(int customerid, LinkedList<Deal> deals,float price) {
    this->customerId = customerid;
    this->deals = deals;
    status = "pending";
    id = orderNo;
    this->TotalPrice = price;
}

void Order::updateStatus() {
    status = "completed";
}
int Order::getId() {
    return id;
}
float Order::getPrice() {
    return TotalPrice;
}
string Order::getStatue() {
    return status;
}

ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order ID: " << order.id
        << ", Price: $" << order.TotalPrice
        << ", Customer ID: " << order.customerId
        << ", Status : " << order.status
        << "Deals are : ";
    order.deals.Display();

    return os;
}
bool Order::operator==(const Order& other) const {
    return this->id == other.id;
}