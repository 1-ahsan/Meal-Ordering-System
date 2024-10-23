#include <iostream>
#include <string>
#include "user.h"

using namespace std;

User::User() : userName("defaultUser") {}
User::User(string name, string pass) {
	this->userName = name;
	this->password = pass;
}
bool User::Login(string name, string pass) {
	if (userName.compare(name) == 0 && password.compare(pass) == 0) {
		return true;
	}
	return false;
}
