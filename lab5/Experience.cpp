#include "Experience.h"
#include <iostream>
using namespace std;

//конструктор класса experience со всеми параметрами
Experience::Experience(int workingyears, int army, int maternityleave) {
	if(workingyears >= 0)
		this->workingyears = workingyears;
	else {
		cout << "Указано недопустимое значение workingyears." << endl;
		this->workingyears = 0;
	}
	if (army >= 0)
		this->army = army;
	else {
		cout << "Указано недопустимое значение army." << endl;
		this->army = 0;
	}
	if (maternityleave >= 0)
		this->maternityleave = maternityleave;
	else {
		cout << "Указано недопустимое значение maternityleave." << endl;
		this->maternityleave = 0;
	}
}

//конструктор класса experience с одним параметром
Experience::Experience(int allfields) {
	if (allfields >= 0) {
		workingyears = allfields;
		army = allfields;
		maternityleave = allfields;
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		workingyears = 0;
		army = 0;
		maternityleave = 0;
	}
}

//конструктор класса experience без параметров
Experience::Experience() {
	workingyears = 0;
	army = 0;
	maternityleave = 0;
}

//метод установки значений
void Experience::set(Experience e) {

}

//метод ввода класса experience
void Experience::input() {
	int workingyears, army, maternityleave;
	cout << "Введите общий стаж (кол-во лет): ";
	cin >> workingyears;
	cout << "Из них в армии (кол-во лет): ";
	cin >> army;
	cout << "Из них в декретном отпуске(кол - во лет): ";
	cin >> maternityleave;
	workingyears = workingyears - army - maternityleave;
	Experience e(workingyears, army, maternityleave);
	this->set(e);
}

//метод вывода
void Experience::output() {
	cout << "Стаж (отработано лет): " << workingyears << endl;
	cout << "Стаж (кол-во лет в армии): " << army << endl;
	cout << "Стаж (кол-во лет в декретном отпуске): " << maternityleave << endl;
}

//метод возвращающий совокупный стаж
float Experience::allexp() {
	int all;
	all = workingyears + army + maternityleave;
	return all;
};

//перегрузка оператора +
Experience operator + (Experience e1, Experience e2) {
	e1.workingyears += e2.workingyears;
	e1.maternityleave += e2.maternityleave;
	e1.army += e2.army;
	return e1;
}

//перегрузка оператора ++ префиксный
Experience& Experience::operator++() {
	this->workingyears += 1;
	this->maternityleave += 1;
	this->army += 1;
	return *this;
}

//перегрузка оператора ++ постфиксный
Experience Experience::operator++(int) {
	Experience temp = *this;
	++* this;
	return temp;
}