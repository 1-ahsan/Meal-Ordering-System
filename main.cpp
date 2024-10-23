#include <iostream>
#include <vector>
#include "Queue.h"
#include "Order.h"
#include "Customer.h"
#include "Admin.h"
#include "DataBase.h"

using namespace std;

int SelectRole();
void showAdminMenu();
void ShowCustomerMenu(int id);



int main() {
	cout << "hello world" << endl;

    DataBase::getAdmin().ViewPendingOrders();

    try {
        int role = SelectRole();
    }
    catch (...) {
        cout << "Sorry! something went wrong here" << endl;
    }

	cout << "hello world" << endl;
	return 0;
}

void AdminLogin() {
    string username, password;
    cout << "Enter the Username : ";
    getline(cin, username);
    cout << "Enter your password : ";
    getline(cin, password);
    if (DataBase::getAdmin().Login(username, password)) {
        showAdminMenu
    }
    else {
        cout << "something went wrong" << endl;
    }
}

void CustomerLogin() {
    try {
        string username, password;
        cout << "Enter the Username : ";
        getline(cin, username);
        cout << "Enter your password : ";
        getline(cin, password);
        cout << "Enter your id";
        int id;
        cin >> id;
        cin.ignore();
        LinkedList<Customer> list = DataBase::getCustomers();
        Customer c(id);
        if (list.getAnyNode(c)->data.Login(username, password)) {
            ShowCustomerMenu(id);
        }
        else {
            cout << "some thing is wrong";
        }
    }
    catch (...) {
        cout << "Sorry! something went wrong here" << endl;
    }

}

int SelectRole() {
    int roleChoice;

    cout << "Welcome to the Meal Ordering System!" << endl;
    cout << "Please select your role:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Customer" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> roleChoice;
    cin.ignore();

    if (roleChoice == 1) {
        showAdminMenu();
        return 1;
    }
    else if (roleChoice == 2) {
        CustomerLogin();
    }
    else {
        cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}

void showAdminMenu() {

    int choice;
    do{
            cout << "\n<<<<<<<<<<Welcome to Admin Portal>>>>>>>>>>\n" << endl;
        cout << "Your opetions are: " << endl;
        cout << " 1. To add customer" << endl;
        cout << "2. To delete a customer" << endl;
        cout << "3. To add new deal" << endl;
        cout << "4. To delete any deal" << endl;
        cout << "5. To edit any deal" << endl;
        cout << "6. view pending orders " << endl;
        cout << "7. view completed orders " << endl;
        cout << "8. Update order status" << endl;
        cout << "9. to logout" << endl;


        cout << endl;
        cout << "Now Enter your choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Option 1: Add customer" << endl;
            DataBase::getAdmin().RegisterNewUser();
            break;
        case 2:
            cout << "Option 2: Delete User Account" << endl;
            DataBase::getAdmin().DeleteUser();
            break;
        case 3:
            cout << "Option 3: Add new Deal" << endl;
            DataBase::getAdmin().AddNewDeal();
            break;
        case 4:
            cout << "Option 4: Delete a deal" << endl;
            DataBase::getAdmin().DeleteDeal();
            break;
        case 5:
            cout << "Option 5: Edit any deal" << endl;
            DataBase::getAdmin().EditAnyDeal();
            break;
        case 6:
            cout << "Option 6: View pending orders" << endl;
            DataBase::getAdmin().ViewPendingOrders();
            break;
        case 7:
            cout << "Option 7: View completed orders" << endl;
            DataBase::getAdmin().ViewCompleteOrders();
            break;
        case 8:
            cout << "Option 8: Update status of an order" << endl;
            DataBase::getAdmin().UpdateOrderStatus();
            break;
        case 9:
            cout << "Option 9: Logout" << endl;
            cout << "Thankyou " << endl;
            return;
            break;
        default:
            cout << "Invalid choice! Please select a valid option (1-9)." << endl;
            break;
        }
    }while(choice != 9);
}

void ShowCustomerMenu(int id) {
    int choice;
    do {

    // Display the menu options
    cout << "Customer Menu:" << endl;
    cout << "1. To view avaliable Deals" << endl;
    cout << "2. To place order" << endl;
    cout << "3. track your order" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    Customer c(id);
    Node<Customer>* customer = DataBase::getCustomers().getAnyNode(c);

    // Apply a switch statement based on the user's choice
        switch (choice) {
        case 1:
            cout << "View Deals" << endl;
            customer->data.ViewDeals();
            break;
        case 2:
            cout << "You chose to place an order." << endl;
            customer->data.AddDealsInOrder();
            break;
        case 3:
            cout << "Track your order" << endl;
            customer->data.TrackYourOrder();
            break;
        case 7:
            cout << "Exiting the menu." << endl;
            // Add code here for exit functionality if needed
            break;
        default:
            cout << "Invalid choice. Please choose a number between 1 and 7." << endl;
            break;
        }
    } while (choice != 7);
}

