//sorting
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RUN = 32;

template <typename T>
void Swap(T& a, T& b) {
	T buf = a;
	a = b;
	b = buf;
}

bool comparator(const int& a, const int& b) {
	return (a > b);
}
	
template <typename T>
void BinarySearch(T& a, int key) {
	int n = a.size();
	int left = 0;
	int right = n - 1;
	int mid;
	
	while (right > left) {
		mid = (left + right) / 2;
		if (a[mid] < key) 
			left = mid++;
		else if (a[mid] > key)
			right = mid--;
		else 
			break;
	}
	cout << "\nbinary search element index: " << mid + 1;
}

template <typename T>
void makeHeap(T& a, int n, int i) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	// если левая ветка больше корня
	if (left < n && a[left] > a[max])
		max = left;
	
	// если правая ветка больше максимального элемента
	if (right < n && a[right] > a[max])
		max = right;
	
	// если максимальный элемент не корень
	if (max != i) {
		Swap(a[i], a[max]);
		makeHeap(a, n, max);
	}
}

template <typename T>
void HeapSort(T& a, int n) {
	// создать кучу
	for (int i = (n / 2) - 1; i >= 0; i--)
		makeHeap(a, n, i);
	
	// выбрать элементы из кучи
	for (int i = n - 1; i >= 0; i--) {
		// переместить текущий корень в конец
		Swap(a[0], a[i]);
		makeHeap(a, i, 0);
	}
}

template <typename T>
void TreeSort(T& a) {
	int n = a.size();
}

// =========================================

template <typename T>
void ShakerSort(T& a) {
	int n = a.size();
}

template <typename T>
void BubbleSort(T& a) {
	int n = a.size();
}

template <typename T>
void InsertSort(T& a) {
	int n = a.size();
}

template <typename T>
void QuickSort(T& a, int left, int right) {	
	int n = a.size();
	
}

template <typename T>
void CombSort(T& a) {
	int n = a.size();
}

template <typename T>
void SelectSort(T& a) {
	int n = a.size();
	
}

template <typename T>
void ShellSort(T& a) {
	int n = a.size();
	for (int step = n / 2; step > 0; step /= 2) {
		for (int i = step; i < n; i++) {
			for (int j = i; j > step && a[i] < a[j - step]; j--)
				Swap(a[i], a[j - step]);
		}
	}
}

template <typename T>
void merge_test(vector<T> a, int left, int right) {
	if (left >= right) return;
	if (right == left + 1 && a[left] > a[right]) {
		Swap(a[left], a[right]);
		return;
	}
	int it1 = 0;
	int it2 = 0;
	int mid = (left + right) / 2;
	
	vector<T> temp;
	
	while (left + it1 <= mid && mid + it2 <= right) {
		if (a[left + it1] < a[mid + it2]) {
			temp[it1 + it2] = a[left + it1];
			it1++;
		} 
	}
}

template <typename T>
void merge(vector<T>& a, int left, int mid, int right) {
	if (left >= right) return;
	if (right == left + 1 && a[left] > a[right]) {
		Swap(a[left], a[right]);
		return;	}
	int iter1 = 0;
	int iter2 = 0;
	
	vector<T> result(right - left);
	
	while (left + iter1 < mid && mid + iter2 < right) {
		if (a[left + iter1] < a[mid + iter2]) {
			result[iter1 + iter2] = a[left + iter1];
			iter1++;
		} else {
			result[iter1 + iter2] = a[mid + iter2];
			iter2++; }	}
	
	while (left + iter1 < mid) {
		result[iter1 + iter2] = a[left + iter1];
		iter1++; }
	
	while (mid + iter2 < right) {
		result[iter1 + iter2] = a[mid + iter2];
		iter2++; }
	
	for (int i = 0; i < iter1 + iter2; i++) {
		a[left + i] = result[i]; }
}

template <typename T>
void MergeSortRecursive(vector<T>& a, int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2; // рекурсивный спуск до массива из двух элементов
	MergeSortRecursive(a, left, mid); 
	MergeSortRecursive(a, mid + 1, right);
	merge(a, left, mid, right);
/*	// слияние
	vector<T> temp;
			
	for (int i = left, j = mid + 1; i <= mid || j <= right;) {
		if (i > mid)
			temp.push_back(a[j++]);
		else if (j > right)
			temp.push_back(a[i++]);
		else if (a[i] <= a[j])
			temp.push_back(a[i++]);
		else temp.push_back(a[j++]);
	}
	
	// копируем отсортированный массив в исходный
	for (int i = 0; i < temp.size(); i++) {
		a[left + i] = temp[i];
	}
*/
}

void merge_test(vector<int>& a, int left, int right) {
	if (left >= right) return;
	
	int mid = (left + right) / 2;
	merge_test(a, left, mid);
	merge_test(a, mid + 1, right);
	
	vector<int> temp;
	for (int i = left, j = mid + 1; i <= mid, j <= right;) {
		if (i > mid) temp.push_back(a[j++]);
		else if (j > mid) temp.push_back(a[i++]);
		else if (a[i] <= a[j]) temp.push_back(a[i++]);
		else temp.push_back(a[j++]);
	}
	
	for (int i = 0; i < temp.size(); i++) {
		a[left + i] = temp[i];
	}
}

template <typename T>
void insertTimSort(T& a, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		for (int j = i; j >= left && a[j] < a[j - 1]; j--)
			Swap(a[j], a[j - 1]);
	}
}

template <typename T>
void TimSort(T& a, int n) {
	// сортировка отдельных массивов размером RUN
	for (int i = 0; i < n; i += RUN)
		insertTimSort(a, i, min((i + RUN - 1), (n - 1)));
	
	// соединение начиная с размера RUN 32
	for (int size = RUN; size < n; size = 2 * size) {
		for (int left = 0; left < n; left += 2 * size) {
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));
			if (mid < right)
				merge(a, left, mid, right);
		}
	}
}

int main() {
	
	vector<int> a{3, 1, 1, 3, 2};
	
	cout << "unsorted: ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << "\n==========";
	
	cout << "\nbubble sort: ";
	BubbleSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout << "\ninsert sort: ";
	InsertSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nselect sort: ";
	a = {3, 1, 1, 3, 2};
	SelectSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\ntim sort: ";
	a = {3, 1, 1, 3, 2};
	TimSort(a, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nshell sort: ";
	a = {3, 1, 1, 3, 2};
	ShellSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nquick sort: ";
	a = {3, 1, 1, 3, 2};
	QuickSort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nmerge sort recursive: ";
	a = {3, 1, 1, 3, 2};
	MergeSortRecursive(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nshaker sort: ";
	a = {3, 1, 1, 3, 2};
	ShakerSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nheap sort: ";
	a = {3, 1, 1, 3, 2};
	//HeapSort2(a, a.size());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\ncomb sort: ";
	a = {3, 1, 1, 3, 2};
	CombSort(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	
	cout <<"\nfunction: ";
	a = {0, 1, 3, 5, 6};
	//func(a);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	//cout << "\nh-index: " << func(a);
	
	// cout <<"\nbinary search: ";
	a = {0, 1, 3, 5, 6};
	BinarySearch(a, 3);
	
	cout << "\n";
	return 0;
}