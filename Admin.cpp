#include <iostream>
#include <vector>
#include <string>
#include "Admin.h"
#include "Deal.h"
#include "LinkedList.h"
#include "Database.h"
using namespace std;

Admin::Admin() {
	this->userName = " ";
	this->password = " ";
}
Admin::Admin(string userName, string password) {
	this->userName = userName;
	this->password = password;
}
void Admin::RegisterNewUser() {
    string username, password, phoneNumber, address;
    int id;

    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Enter customer address: ";
    getline(cin, address);
    cout << "Enter customer id: ";
    cin >> id;
    cin.ignore(); 
    Customer newCustomer(username, id, password, address, phoneNumber);

    
    DataBase::addCustomer(newCustomer);
    cout << "User registered successfully!\n";
	
}
void Admin::DeleteUser() {
    cout << "Enter the id of user you want to delete : ";
    int id = 0;
    cin >> id;
    try {
        Customer c(id);
        DataBase::getCustomers().deleteNode(c);
    }
	catch (...) {
		cout << "Sorry! you entered wrong id." << endl;
	}
}
void Admin::AddNewDeal() {
    string name, discription;
    float price;
    cout << "Enter Name of Deal : ";
    getline(cin, name);
    cout << "Enter the disctiption  :  " << endl;
    getline(cin, discription);
    cout << "Enter the prie : ";
    cin >> price;
    cin.ignore();

    Deal d(name, price, discription);
    DataBase::getDeals().insert(d);

    cout << "Successfully Added........" << endl;
}
void Admin::DeleteDeal() {
    cout << "Enter deal id";
    int id;
    cin >> id;
    cin.ignore();

    try {
        Deal d(id);
        DataBase::getDeals().deleteNode(d);
    }
    catch (...) {
        cout << "Sorry! you entered wrong id." << endl;
    }
}
void Admin::EditAnyDeal() {
    cout << "Enter deal id";
    int id;
    cin >> id;
    cin.ignore();
    
    string name, discription;
    float price;
    cout << "\n<<< Enter new Details >>>\n" << endl;
    cout << "Enter new Name of Deal : ";
    getline(cin, name);
    cout << "Enter new the disctiption  :  " << endl;
    getline(cin, discription);
    cout << "Enter new the prie : ";
    cin >> price;
    cin.ignore();

    try{
        Deal deal(id);
        Node<Deal>* pdeal= DataBase::getDeals().getAnyNode(deal);
        pdeal->data.Update(name, price, discription);
    }
    catch (...) {
        cout << "Sorry! you entered wrong id." << endl;
    }
}
void Admin::ViewPendingOrders() {
    Queue<Order> list = DataBase::getPendingOrders();
    list.Display();
}
void Admin::ViewCompleteOrders() {
    Queue<Order> list = DataBase::getCompletedOrders();
    list.Display();
}
void Admin::UpdateOrderStatus() {
    cout << "Enter order id";
    int id;
    cin >> id;
    cin.ignore();
    try {
        Order order(id);
        Order* porder= DataBase::getPendingOrders().GetNodeByID(order);
        porder->updateStatus();
        DataBase::getCompletedOrders().Enqueue(*porder);
        DataBase::getPendingOrders().Dequeue();
    }
    catch (...) {
        cout << "wrong id" << endl;
    }
}