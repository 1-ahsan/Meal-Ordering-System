#pragma once
#include <iostream>
using namespace std;


template <class T1>
class Queue {
	struct Node {
		T1 data;
		Node* next;
		Node(T1 value) {
			this->data = value;
			next = nullptr;
		}
	};
	Node* front;
	Node* rare;
	int size;
public:
	Queue() {
		front = rare = nullptr;
		size = 0;
	}
	bool isEmpty() const {
		if (rare == nullptr) {
			return true;
		}
		return false;
	}
	void Enqueue(T1 id) {
		Node* newNode = new Node(id);
		if (isEmpty()) {
			rare = newNode;
			front = newNode;
			size++;
			return;
		}
		rare->next = newNode;
		rare = newNode;
		size++;
		return;
	}
	void Dequeue() {
		if (isEmpty()) {
			cout << "Nothing is remaining." << endl;
		}
		Node* temp = front;
		front = front->next;
		delete temp;
		size--;
	}
	T1 peek() const {
		if (isEmpty()) {
			throw out_of_range("Queue is empty, cannot peek.");
		}
		return front->data;
	}
	void Display() {
		if (isEmpty()) {
			cout << "Nothing is remaining." << endl;
			return;
		}
		Node* temp = front;
		while (temp->next != nullptr) {
			cout << temp->data;
			temp = temp->next;
		}
	}
	int Getsize() const {
		return size;
	}
	T1* GetFront() {
		return front;
	}
	T1* GetRare() {
		return rare;
	}
	T1* GetNodeByID(T1 value) {
		if (isEmpty()) {
			throw "empty";
		}
		Node* temp = front;
		while (temp->next != nullptr) {
			if (temp->data == value) {
				return &temp->data;
			}
		}
		throw "not found";

	}
};