#include <iostream>
#include <random>
#include <string>
#include <cstring>

using namespace std;


void TrimRight(char*);
void TrimRightString(string&);
template <typename T>
void _testTrimRight(void(*)(T), const size_t&);

// вариант реализации 
void TrimRight(char* s) {
	// проверяем чтобы строка была непустой
	if (!*s) { 
		cerr << "error: string empty\n";
		return;
	}
	// переставляем указатель на предпоследний элемент и движемся с конца строки
	for (s += strlen(s) - 1; s != 0; s--) {
		// сдвигаем указатель пока попадется символ, отличный от пробела
		// на место последнего пробела устанавливаем символ окончания строки \0 и выходим из функции
		if (*s != ' ') {
			++s;
			*s = '\0';
			break;
		}
	}
}

// вариант реализации 2 через std::string
void TrimRightString(string& s) {
	// проверяем чтобы строка была непустой
	if (!s.size()) { 
		cerr << "error: string empty\n";
		return;
	}
	s.erase(s.find_last_not_of(" ") + 1);
}

// тестирование функции
template <typename T>
void _testTrimRight(void(*op)(T), const size_t& length) {
	const char chars[] =
"0123456789 !@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	mt19937 mt(time(nullptr));
	size_t n = strlen(chars);
	char test_string[length];
	for (size_t i = 0; i < length; i++) test_string[i] = chars[mt() % (n - 1)];
	op(test_string);
	for (auto ch : test_string) cout << ch;
}

int main() {	
	char a[] = " ";
	cout << a << "[end]";
	TrimRight(a);
	cout << a << "[end]";
	// протестировать функцию с указанной длиной тестовой строки
	cout << "enter test string length: ";
	size_t n; cin >> n;
	_testTrimRight(TrimRight, n);
    return 0;
}
