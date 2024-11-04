// nodes

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {	
	Node* next;
	int& data;
	Node(int& _data) : next(nullptr), data(_data) {}
};

class Queue {
private:
	Node* head;
	int size;
public:
	Queue() : head(nullptr), size(0) {}
	void print();
	void push(int&);
	void pop();
	void getElement();
	void reverse();
	void reverse_recursive_v2();
};


void Queue::print() {
	cout << "list size: " <<  size << "\n";
	
	if (!head) {
		return;
	}
	
	Node* current = head;
	while (current) {
		cout << current->data << "\n";
		current = current->next;
	}
}

void Queue::push(int& _data) {
	Node* node = new Node(_data);
	if (!head) {
		head = node;
	} else {
		node->next = head;
		head = node;
	}
	size++;
}

void Queue::pop() {
	
}

void Queue::getElement() {
	Node* current = head;
	while (current->next) {
		
	}
}

void Queue::reverse() {
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		Node* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Queue::reverse_recursive_v2() {
	if (head != nullptr && head->next != nullptr) {
		Node* current = head;
		head = head->next;
		
		reverse_recursive_v2();
		
		current->next->next = current;
		current->next = nullptr;
	}
}

int main() {
	Queue q;
	int a = 1, b = 2, c = 3, d = 4;
	
	q.push(a);
	q.push(b);
	q.push(c);
	q.push(d);
	q.print();
	
	q.reverse();
	q.print();
	
	q.reverse_recursive_v2();
	q.print();
	
	cout << "\n";
	return 0;
}