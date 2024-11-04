#include <iostream>
#include "tree.h"
#include <queue>

using namespace std;

int main() {
	BinaryTree tree(2);
	tree.addNode(5);
	tree.addNode(7);
	tree.addNode(22);
	tree.addNode(6);
	tree.addNode(15);
	tree.addNode(1);
	tree.addNode(11);
	tree.print_tree();
	tree.print_tree2();
	cout << tree.findNode(5);
	
	cout << "\n";
	return 0;
}
