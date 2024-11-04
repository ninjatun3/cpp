/*

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
	std::atomic<int> head;
	std::atomic<int> tail;
	std::atomic<bool> isOverwritten;
public:
	CircularQueue() : head(-1), tail(-1), isOverwritten(false) {
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
	
	// проверка на непустую очередь
	bool empty() {
		return (head < 0 && tail < 0);
	}
	
	// печать очереди
	void print() {
		if (!empty()) {
			for (size_t i = 0; i < capacity; i++) {
				std::cout << a[i].data << " ";
			}
		} else std::cout << "queue is empty\n";
	}
	
	// добавление элемента
	void push(const TClass& element) {
		if (empty()) {
			head = 0;
			tail = 0;
		}
		if (tail >= capacity) {
			tail = tail % capacity;
			isOverwritten = true;
		}
		a[tail] = element;
		tail++;
	}
	
	// получение первого элемента очереди
	const TClass front() {
		if (!empty()) {
			if (isOverwritten) head += tail;
			return a[head];
		} return -1;
	}
	
	// получение последнего элемента очереди
	const TClass back() {
		if (!empty()) {
			if (!tail) return a[tail];
			else return a[tail - 1];
		} else return -1;
	}
};

int main() {
	
	CircularQueue< T<int>, 5 > a;

	a.push(T<int>(1));
	a.push(T<int>(2));
	a.push(T<int>(3));
	
	a.print();
	
	
	T<int> front_element;
	std::thread t1(&CircularQueue< T<int>, 5 >::push, std::ref(a), T<int>(3));
	std::thread t2( [&front_element, &a]() {front_element = a.front();} );
	t1.join();
	t2.join();
	
	std::cout << "front " << front_element.data;
	
	std::cout << "\n";
	return 0;
}
*/