// sorting 

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Swap(T& a, T& b) {
	T buf;
	buf = a;
	a = b;
	b = buf;
}

template <typename T>
void InsertSort(vector<T>& a) {
	int n = a.size();
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && a[j] < a[j - 1]; j--) {
			Swap(a[j], a[j - 1]);
		}
	}
}

template <typename T>
void SelectSort(vector<T>& a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				Swap(a[i], a[j]);
			}
		}
	}
}


int main() {
	vector<double> a{3, 5, 1, 1, 2, 4, 4};
	
	InsertSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout << "\n";
	a = {3, 5, 1, 1, 2, 4, 4};
	SelectSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}	
	
	cout << "\n";
	return 0;
}
