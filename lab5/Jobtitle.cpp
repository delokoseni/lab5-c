#include "Jobtitle.h"
#include "checkfileextension.h"
#include "Subordinates.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//конструктор класса jobtitle со всеми параметрами
Jobtitle::Jobtitle(string jtitle, int hourlycost, Subordinates subs) {
	this->jtitle = jtitle;
	if (hourlycost >= 0)
		this->hourlycost = hourlycost;
	else {
		cout << "Указано недопустимое значение hourlycost." << endl;
		this->hourlycost = 0;
	}
	this->subs = subs;
}

//конструктор класса jobtitle с одним параметром
Jobtitle::Jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		hourlycost = allfields;
		Subordinates s(allfields);
		subs = s;
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		jtitle = "";
		hourlycost = 0;
		Subordinates s;
		subs = s;
	}
}

//конструктор класса jobtitle без параметров
Jobtitle::Jobtitle() {
	jtitle = "";
	hourlycost = 0;
	Subordinates s;
	subs = s;
}

//метод установки значений 
void Jobtitle::set(Jobtitle j) {
	this->jtitle = j.jtitle;
	this->hourlycost = j.hourlycost;
	this->subs.set(j.subs);
}

//метод ввода класса jobtitle
void Jobtitle::input() {
	string jtitle;
	int hourlycost;
	Subordinates subs;
	cout << "Введите должность: ";
	getline(cin, jtitle);
	cout << "Введите стоимость часа работы: ";
	cin >> hourlycost;
	subs.input();
	Jobtitle j(jtitle, hourlycost, subs);
	this->set(j);
}

//метод вывода
void Jobtitle::output() {
	cout << "Должность: " << jtitle << endl;
	cout << "Стоимость часа работы: " << hourlycost << endl;
	subs.output();
}

//метод сравнения зарплаты с заданной
float Jobtitle::comparisonhc(float hcost) {
	float percent;
	float d = hourlycost;
	percent = d / (hcost / 100) - 100;
	return percent;
}

//метод возвращающий количество подчиненных сотрудника
int Jobtitle::getamount() {
	return subs.getamount();
}

//метод для редактирования должности
void Jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//строковый поток
	stringstream ss(this->jtitle);
	//посдчет количества слов в строке
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string *words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for(i = 0; i < n; i++) {
		//если строки одинаковые
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

//перегрузка оператора +
Jobtitle Jobtitle::operator + (Jobtitle j1){
	hourlycost += j1.hourlycost;
	subs = j1.subs + j1.subs;
	jtitle += j1.jtitle;
	return *this;
}

//перегрузка оператора ++ префиксный
Jobtitle& Jobtitle::operator++() {
	this->hourlycost += 1;
	this->subs++;
	return *this;
}

//перегрузка оператора ++ постфиксный
Jobtitle Jobtitle::operator++(int) {
	Jobtitle temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	file << jtitle << "\t";
	file << hourlycost << "\t";
	subs.tofile(file, filename);
}

//метод ввода из файла
void Jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("Использовано недопустимое расширение файла. Допустимое расширение: \".txt\".\n");
	int flag = 0;
	string buff;
	try {
		file >> jtitle;
		while (!flag) {
			file >> buff;
			if (buff[0] >= '0' && buff[0] <= '9') {
				hourlycost = stoi(buff);
				flag = 1;
			}
			else {
				jtitle += " ";
				jtitle += buff;
			}
		}
		subs.getfromfile(file, filename);
	}
	catch (exception& e) {
		throw exception("В файле недостаточно данных для записи  или неверно указано имя файла.\n");
	}

}