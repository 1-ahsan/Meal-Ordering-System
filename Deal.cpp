#include<iostream>
#include "Deal.h"
using namespace std;

int Deal::no = 001;

// Parameterized constructor
Deal::Deal(int id) {
    this->price = 0;
    this->id = id;
}
Deal::Deal(string dealName, float dealPrice, string dealDescription) {
    this->name = dealName;
    this->id = no;
    this->price = dealPrice;
    this->description = dealDescription;
    no++;
}

// Getters
string Deal::getName() const {
    return name;
}

int Deal::getId() const {
    return id;
}

float Deal::getPrice() const {
    return price;
}

string Deal::getDescription() const {
    return description;
}

// Setters
void Deal::setName(const string& dealName) {
    name = dealName;
}

void Deal::setId(int dealId) {
    id = dealId;
}

void Deal::setPrice(float dealPrice) {
    price = dealPrice;
}

void Deal::setDescription(const string& dealDescription) {
    description = dealDescription;
}

void Deal::ViewDeal() const{
    cout << "------------------" << endl;
    cout << "Deal Name :      " << this->name << endl;
    cout << "Deal Price :     " << this->price << endl;
}
void Deal::Update(string dealName, float dealPrice, string dealDescription) {
    this->name = dealName;
    this->price = dealPrice;
    this->description = dealDescription;
}

bool Deal::operator==(const Deal& other) const {
    return this->id == other.id; // Compare IDs
}
bool Deal::operator!=(const Deal& other) const {
    return this->id != other.id; // Compare IDs
}
ostream& operator<<(ostream& os, const Deal& deal) {
    os << "Deal Name: " << deal.name << ", Price: $" << deal.price;
    return os;
}