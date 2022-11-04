#include "Employee.h"
#include <string>
#include <stdio.h>
#include <iostream>

int Employee::counter = 0;
//конструктор класса employee со всеми параметрами
Employee::Employee(Experience e, Hours h, Jobtitle j) {
	counter++;
	id = counter;
	exp = e;
	hour = h;
	jt = j;
}

//конструктор класса employee с одним параметром
Employee::Employee(int allfields) {
	counter++;
	id = counter;
	if (allfields >= 0) {
		Experience e(allfields);
		Hours h(allfields);
		Jobtitle j(allfields);
		exp = e;
		hour = h;
		jt = j;
	}
	else {
		cout << "Указано недопустимое значение allfields." << endl;
		Experience e;
		Hours h;
		Jobtitle j;
		exp = e;
		hour = h;
		jt = j;
	}
}

//конструктор класса employee без параметров
Employee::Employee() {
	counter++;
	id = counter;
	Experience e;
	Hours h;
	Jobtitle j;
	exp = e;
	hour = h;
	jt = j;
}

//метод полного вывода employee
void Employee::output() {
	cout << "ID: " << this->id << endl;
	exp.output();
	hour.output();
	jt.output();
}

//метод ввода employee
void Employee::input() {
	exp.input();
	hour.input();
	while (getchar() != '\n');
	jt.input();
}

//метод подсчета зарплаты
int Employee::getsalary(Salary sal){
	int salary = 0;
	salary += hour.hoursmoney(jt, sal);
	salary = sal.allmoney(salary, exp, jt);
	return salary;
}

//метод подсчета премии (положена или нет)
string Employee::getpremium(int houramount) {
	if (hour.allhours() < houramount)
		return "Премия не положена";
	else
		return "Премия положена";
}

//метод вывода счетчика количества сотрудников
void Employee::printcounter() {
	cout << "Количество сотрудников: " + counter << endl;
}

//метод уменьшения количества сотрудников
void Employee::minuscounter() {
	counter--;
	cout <<"Количество сотрудников уменьшено на 1." << endl;
}
//метод уменьшения количества сотрудников
void Employee::minuscounter(int number) {
	int x = counter;
	counter = counter - number;
	cout << "Количество сотрудников уменьшено c " << x << " до " << counter << endl;
}

//метод обращения к методу внутреннего класса
void Employee::editjtitle(string jtitle, string add) {
	jt.editjtitle(jtitle, add);
}

//метод, возвращающий значение через указатель
Employee* Employee::get() {
	return this;
}

//метод, возвращающий значение через ссылку
Employee& Employee::getadress() {
	return *this;
}

//перегрузка оператора +
Employee Employee::operator + (Employee e1) {
	exp = exp + e1.exp;
	hour = hour + e1.hour;
	jt = jt + e1.jt;
	return *this;
}

//перегрузка оператора ++ префиксный
Employee& Employee::operator++() {
	this->exp++;
	this->hour++;
	this->jt++;
	return *this;
}

//перегрузка оператора ++ постфиксный
Employee Employee::operator++(int) {
	Employee temp = *this;
	++* this;
	return temp;
}

//метод записи в файл
void Employee::tofile(ofstream& file) {
	file << counter << "\t";
	file << id << "\t";
	exp.tofile(file);
	hour.tofile(file);
	jt.tofile(file);
}

//метод записи из файла
void Employee::getfromfile(ifstream& file) {
	file >> counter;
	file >> id;
	exp.getfromfile(file);
	hour.getfromfile(file);
	jt.getfromfile(file);
}
