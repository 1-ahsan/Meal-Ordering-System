#include "Customer.h"
#include "DataBase.h"
#include <iostream>
#include <string>
using namespace std;

Customer::Customer(int id) {
	this->id = id;
}

Customer::Customer(const string username, int id, const string password, const string address, const string phoneNumber){
	this->userName = username;
	this->id = id;
	this->password = password;
	this->address = address;
	this->phoneNumber = phoneNumber;
}


bool Customer::Login(string name, string pass) const {
	if (userName.compare(name) and password.compare(pass)) {
		return true;
	}
	return false;
}
void Customer::ChangePasseord() {
	string oldpassword;
	cout << "Enter your old password : ";
	getline(cin, oldpassword);
	if (this->password.compare(oldpassword)) {
		cout << "Now enter New password : ";
		string newPassword;
		getline(cin, newPassword);
		this->password = newPassword;
		cout<<"Password changed successfully."<<endl;
		return;
	}
	cout << "Sorry you entered wrong password." << endl;
}
int Customer::getId() const {
	return id;
}

void Customer::ViewDeals() {
	LinkedList<Deal> list = DataBase::getDeals();
	list.Display();
}
void Customer::AddDealsInOrder() {
	int choice;
	float price = 1;
	do {
		cout << "Enter deal id you want ";
		int id = 0;
		cin >> id;
		cin.ignore();
		Deal deal(id);
		cart.insert(deal);
		price *=DataBase::getDeals().getAnyNode(deal)->data.getPrice();

		cout << "sucessfully added";
		cout << "\n do you want to add another press 1 elee 2";
		cin >> choice;
	} while (choice != 2);
	Order order(this->id, cart,price);
	cout << "Your order id : " << order.getId() << " and Price $ " << order.getPrice() << endl;
	
}
void Customer::TrackYourOrder() {
	cout << "Ener your order id : ";
	int id;
	cin >> id;
	Order order(id);
	Order* porder=DataBase::getPendingOrders().GetNodeByID(order);
	cout << "your status is : " << porder->getStatue() << endl;
}

bool Customer::operator==(const Customer& other) const {
	return this->id == other.id; // Compare IDs
}
bool Customer::operator!=(const Customer& other) const {
	return this->id != other.id; // Compare IDs
}