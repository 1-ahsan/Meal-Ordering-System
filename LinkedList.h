#pragma once
#include<iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode; 
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next; 
            }
            current->next = newNode; 
        }
    }

    void deleteNode(T value) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next; 
            delete temp;
            cout << "Deleted....." << endl;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            throw string("Not found");
            return;
        }
        previous->next = current->next;
        delete current; 
        cout << "Deleted....." << endl;
    }

    Node<T>* getAnyNode(T value) {
        Node<T>* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return current;
    }
    void Display() const {
        if (head == nullptr) {
            cout << "Nothing is remaining." << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
    }

};
