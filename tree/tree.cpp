#include <iostream>
#include "tree.h"
#include <queue>

using namespace std;

// двоичное дерево

BinaryTree::BinaryTree(const int& key) {
	root = new Node(key);
	size = 1;
}

BinaryTree::~BinaryTree() {
	delete_tree(root);
}

void BinaryTree::delete_tree(Node* node) {
	if (node) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}

void BinaryTree::addNode(const int& key) {
	Node* iter = root;
	while (iter && iter->key != key) {
		if (iter->key > key && !iter->left) {
			iter->left = new Node(key);
			size++;
			return;
		}
		if (iter->key < key && !iter->right) {
			iter->right = new Node(key);
			size++;
			return;
		}
		if (iter->key > key)
			iter = iter->left;
		else 
			iter = iter->right;
	}
}

void BinaryTree::print_tree() {
	print(root);
	cout << "\n";
}

void BinaryTree::print_tree2() {
	print2(root);
	cout << "\n";
}

void BinaryTree::print(Node* iter) {
	if (iter) {
		print(iter->left);
		cout << iter->key << " ";
		print(iter->right);
	}
}


void BinaryTree::print2(Node* iter) {
	queue<Node*> q;
	q.push(iter);
	while (!q.empty()) {
		Node* x = q.front();
		q.pop();
		cout << x->key << " ";
		if (x->left) {
			q.push(x->left);
		}
		if (x->right) {
			q.push(x->right);
		}
	}
	
}

bool BinaryTree::findNode(const int& key) {
	Node* iter = root;
	while (iter && iter->key != key) {
		if (iter->key > key) {
			iter = iter->left;
		} else {
			iter = iter->right;
		}
	}
	return iter != nullptr;	
}

// односвязный список
/*
List::List(const int& data) {
	head = new Node*(data);
	size = 1;
}

List::~List() {
	delete_list(head);
}

void List::delete_list(Node* iter) {
	if (iter) {
		delete_list(iter->next);
		delete head;
	}
}

void List::push_front(const int& data) {
	Node* iter = head;
	Node* new_node = new Node(data);
	if (iter) {
		new_node->right = head;
		head = new_node;
	} else 
		head = new_node;
}

void List::push_back(const int& data) {
	
}
*/