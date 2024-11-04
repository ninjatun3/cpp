#include <iostream>
#include <thread>
#include <atomic>

// можно использовать
//const std::lock_guard<std::mutex> lg(lock);

// класс типа данных T с шаблонным полем данных
template <typename TData>
struct T {
	TData data;
	T() {}
	T(const TData& _data) : data(_data) {}
	T(const T& obj) : data(obj.data) {}	// конструктор копирования
};

// класс циклической очереди с двумя шаблонными параметрами
template <class TClass, size_t capacity>
class CircularQueue {
	TClass a[capacity];
	std::atomic<size_t> head;
	std::atomic<size_t> tail;
	std::atomic<bool> isOverwritten;
public:
	CircularQueue() : head(0), tail(0), isOverwritten(false) {
		for (size_t i = 0; i < capacity; i++) {
			a[i].data = 0;
		}
	}
	
	// конструктор копирования
	CircularQueue(const CircularQueue& obj) { 
		for (size_t i = 0; i < capacity; i++) {
			a[i].data = obj.a[i].data;
		}
		head = obj.head;
		tail = obj.tail;
		isOverwritten = obj.isOverwritten;
	}
	
	// переопределение оператора присваивания
	CircularQueue& operator=(const CircularQueue& obj) { 
		if (&obj != this) {
			for (size_t i = 0; i < capacity; i++) {
				a[i].data = obj.a[i].data;
			}
			head = obj.head;
			tail = obj.iter;
			isOverwritten = obj.isOverwritten;
		}
		return *this;
	}
	
	
	// печать очереди
	void print() {
		for (size_t i = 0; i < capacity; i++) {
			std::cout << a[i].data << " ";
		}
		std::cout << "\n";
	}
	
	// добавление элемента
	void push(const TClass& element) {
		if (tail >= capacity) {
			tail = tail % capacity;
			isOverwritten = true;
		}
		a[tail] = element;
		tail++;
	}
	
	// получение первого элемента очереди
	const TClass front() {
		if (isOverwritten) head += tail;
		return a[head];
	}
	
	// получение последнего элемента очереди
	const TClass back() {
		if (!tail) return a[tail];
		else return a[tail - 1];
	}
};

int main() {
	
	CircularQueue< T<int>, 5 > a;

/*
	a.push(T<int>(1));
	a.push(T<int>(2));
	a.push(T<int>(3));
*/	
	
	a.print();
	
	// пример потока записи и чтения
	T<int> front_element;
	std::thread t1(&CircularQueue< T<int>, 5 >::push, std::ref(a), T<int>(3));
	std::thread t2( [&front_element, &a]() {front_element = a.front();} );
	t1.join();
	t2.join();
	
	a.print();
	
	std::cout << "\nfront " << front_element.data;
	
	std::cout << "\n";
	return 0;
}
