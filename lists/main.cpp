// lists

#include <iostream>

using namespace std;


class node {
public:
	node *next;
	node *prev;
	double data;
public:
	node(double data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class doubleLinkedList {
public:
	node *head;
	node *tail;
public:
	doubleLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	node* push_front(double data);
	node* push_back(double data);
	void pop_front();
	void pop_back();
};

node* doubleLinkedList::push_front(double data) {
		node *new_item = new node(data);
		new_item->next = head;
		
		if (head != NULL) {
			head->prev = new_item;
		}
		if (tail == NULL) {
			tail = new_item;
		}
		head = new_item;
		
		return new_item;
}

node* doubleLinkedList::push_back(double data) {
		// создаем элемент и подцепляем его к последнему в списке
		node *new_item = new node(data);
		new_item->prev = tail;
		if (tail != NULL) {
			tail->next = new_item;
		}
		if (head == NULL) {
			head = new_item;
		}
		tail = new_item;
		
		return new_item;
}

void doubleLinkedList::pop_front() {
	node *new_item = new node(data);
	if (head == NULL) return;
	
	new_item = head->next;
	if (new_item != NULL) {
		new_item->prev = NULL;
	}
	else tail = NULL;
	delete head;
	head = new_item;
}

void doubleLinkedList::pop_back() {
	if (tail == NULL) return;
	new_item = tail->prev;
	if (new_item != NULL) {
		new_item = tail;
	}
	else head = NULL;
	delete tail;
	tail = new_item;  
}


int main() {
	
	
	cout << "\n";
	return 0;
}
