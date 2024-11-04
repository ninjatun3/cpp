#pragma once

#include <iostream>
#include "tree.h"
#include <queue>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int key;
	Node(const int& new_key) : left(nullptr), right(nullptr), key(new_key) {}
};

class BinaryTree {
private:
	Node* root;
	size_t size{0};
public:
	BinaryTree(const int&);
	~BinaryTree();
	void getSize();
	void print(Node*);
	void print_tree();
	void print2(Node*);
	void print_tree2();
	void addNode(const int&);
	void delete_tree(Node*);
	bool findNode(const int&);
};

class List {
private:
	Node* head;
	size_t size{0};
public:
	List(const int&);
	~List();
	void print();
	void push_front(const int&);
	void push_back(const int&);
	void pop();
	void delete_list(Node*);
	void reverse();
};