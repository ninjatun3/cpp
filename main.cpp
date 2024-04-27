#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void allSwap(T& _a, T& _b)
{
    T temp = _a;
    _a = _b;
    _b = temp;
}


template <typename Element>
void BubbleSort(Element& _arr) {
	int n = _arr.size();
	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (_arr[j] > _arr[j + 1]) {
				allSwap(_arr[j], _arr[j + 1]);
			}
		}
	}
}


template <typename Element>
void InsertSort(Element& _arr) {
	int n = _arr.size();
	for (int i = 1; i < n; i++) {
		for (int j = i; (j > 0) && (_arr[j] < _arr[j - 1]); j--) {
			allSwap(_arr[j], _arr[j - 1]);
		}
	}
}


template <typename Element> void ChoiceSort(Element& _arr) {
	int n = _arr.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if(_arr[i] > _arr[j]) {
				allSwap(_arr[i], _arr[j]);
			}
		}
	}
}


int main()
{
	vector<int> a{5, 1, 3, 3, 4, 2, 2};
	int n = a.size();
	/*int n;
	cout << "size?\n";
	cin >> n;
	
	// заполинть
	for (int i = 0; i < n; i++) {
		a.push_back(n - i);
	}
	*/
	
	cout << "unsorted: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	// сортировка
	cout << "\nbubble sort: ";
	BubbleSort(a);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << "\ninsert sort: ";
	a = {5, 1, 3, 3, 4, 2, 2};
	InsertSort(a);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << "\nchoice sort: ";
	a = {5, 1, 3, 3, 4, 2, 2};
	ChoiceSort(a);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << endl;
	return 0;
}
