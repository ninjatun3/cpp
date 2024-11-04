#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std; // небезопасно, но для читаемости

size_t getRandomNumber(const size_t&, const size_t&); // генерация случайного числа в заданном диапазоне
void getTime(); // вывод времени с секундами
void func(size_t, size_t); // функция для выполнения внутрипотоков
	
// исходные данные
static size_t n; // искомое число 1-10
static size_t iter; // количество итераций 1-9999
static size_t num_of_threads; // количество потоков 1-99
static size_t q; // квант времени в сек 1-9
static atomic<size_t> counter = 0; // атомарный счетчик для всех потоков

// генерация случайного числа в заданном диапазоне
size_t getRandomNumber(const size_t& min, const size_t& max) {
	auto rnd = random_device{};
    auto gen = mt19937_64{rnd()};
    auto dis = uniform_int_distribution<size_t>{min, max};
    return dis(gen);
}

// вывод времени с секундами
void getTime() {
	time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
	string s(15, '\0');
	strftime(&s[0], s.size(), "%H:%M:%S", localtime(&now));
	cout << s << " ";
}

// функция для запуска внутри потока
void func(size_t quant, size_t id) {
	getTime();
	cout << "thread " << id << " started\n";
	while (counter != iter) {
		counter++;
		size_t r = getRandomNumber(1, 10);
		size_t timeout = getRandomNumber(0, quant);
		getTime();
		cout << "thread " << id << " generated number: " << r << "\n";
		this_thread::sleep_for(chrono::milliseconds(timeout));
		if (r == n) {
			// выход если найдено число
			getTime();
			cout << "thread " << id << " exited with number found: " << r << "\n";
			break;
		}
	}
	// выход если достигнуто кол-во итераций
	if (counter == iter) {
		getTime();
		cout << "thread " << id << " exited with iteration limit reached\n";
	}
}

int main() {
	// ввод параметров
	cout << "enter n 1-10: "; cin >> n;
	cout << "enter number of threads 1-99: "; cin >> num_of_threads;
	cout << "enter number of iterations 1-9999: "; cin >> iter; 
	cout << "enter time quant 1-9 sec: "; cin >> q; 
	
	// создание потоков
	vector<thread> threads;
	for (size_t i = 1; i <= num_of_threads; i++) {
		threads.push_back(thread(func, q * 1000, i));
	}
	
	// запуск потоков
	for (size_t i = 0; i < threads.size(); i++) {
		threads[i].join();
	}

	// завершение работы
	return 0;
}