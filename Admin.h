#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class Admin : public User{
public:
	Admin();
	Admin(string username, string password);
	void RegisterNewUser();
	void DeleteUser();
	void AddNewDeal();
	void DeleteDeal();
	void EditAnyDeal();
	void ViewPendingOrders();
	void ViewCompleteOrders();
	void UpdateOrderStatus();
};