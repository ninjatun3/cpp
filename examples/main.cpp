#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class A
{
    public:
    virtual int get(void){ return 0;};
};

class B: public A
{
    public:
    virtual int get(void) override { return 1;};
};

int main() {
	
	A* a;    
    a = new B();
    int k = a->get();
	
	cout << k;
	
	std::cout << "\n";
	return 0;
}
