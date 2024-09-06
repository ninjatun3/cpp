// master
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstring>
#include <algorithm>
#include <map>
#include <stdarg.h>

using namespace std;

// глава 7
// 1
void func1(char* s);
void func2(int& a);
void (*ptr_func2) (int&);
void func3 (int* ptr_func2);
typedef int (*ptr_f)(int(*ptr_f)(int));

void helloworld(int count, ... ) {
	va_list ap;
	char* a;
	va_start(ap, count);
	
	for(int i = 0; i < count; i++) {
		a = va_arg(ap, char*);
		printf("Hello, %s", a);
		cout << "\n";
	}
	
	va_end(ap);
}


// 7
struct Tnode {
	string word;
	int count;
	Tnode* left;
	Tnode* right;
};

void addWord(Tnode* node, string word) {
}

int main() {
// 2
	// определение типа int как ссылки на функцию с двумя аргументами типа int
	typedef int (&rifii) (int, int);
	
// 3
	char name[20];
	char name2[20];
	cin >> name >> name2;
	helloworld(2, name, name2);
	
// 4
// 5
// 6
	

// глава 6
// 3
/*
	map<string, double> pairs;
	int n;
	cout << "enter number of pairs: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string a;
		double b;
		cin >> a;
		cin >> b;
		pairs[a] = b;
	}
	
	map<string, double> :: iterator it = pairs.begin();
	double sum = 0;
	for (int i = 0; it != pairs.end(); it++, i++) {
		sum += it->second;
	}
	
	cout << "av: " << sum / n;
*/
	
	cout << "\n";
	return 0;
}