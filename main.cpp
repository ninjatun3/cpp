// master

#include <iostream>
#include <vector>

using namespace std;

class Vector3 {
private:
	vector<double> a{0, 0, 0};
public:
	Vector3();
	Vector3(vector<double> _a) : a(_a) {};
	friend double operator * (const Vector3& v1, const Vector3& v2);
};


double operator * (const Vector3& v1, const Vector3& v2) {
	double mul = 0;
	for (int i = 0; i < 3; i++) {
		mul += v1.a[i] * v2.a[i];
	}
	return mul;
}


int main() {
	vector<double> a;
	vector<double> b;
	double x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < 3; i++) {
		cin >> x;
		b.push_back(x);
	}
	
	Vector3 v1(a);
	Vector3 v2(b);
	
	double mul = v1 * v2;
	cout << mul;
		
	cout << "\n";
	return 0;
}
