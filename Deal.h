#pragma once
#include<iostream>
using namespace std;

class Deal {
private:
    string name;
    int id;
    float price;
    string description;
    static int no;
public:

    // Parameterized constructor
    Deal(int id);
    Deal(string dealName, float dealPrice, string dealDescription);

    // Getters
    string getName() const;
    int getId() const;
    float getPrice() const;
    string getDescription() const;

    // Setters
    void setName(const string& dealName);
    void setId(int dealId);
    void setPrice(float dealPrice);
    void setDescription(const string& dealDescription);

    void ViewDeal() const;
    void Update(string dealName, float dealPrice, string dealDescription);

    bool operator==(const Deal& other) const; // Comparison operators for LinkedList
    bool operator!=(const Deal& other) const;
    friend ostream& operator<<(std::ostream& os, const Deal& deal);
};