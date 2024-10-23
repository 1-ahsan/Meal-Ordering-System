#pragma once
#include <iostream>
using namespace std;

class User {
protected:
	string userName;
	string password;
public:
	User();
	User(string name, string pass);
	bool Login(string name, string pass);
};