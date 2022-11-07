#pragma once
#include <fstream>
using namespace std;

class Subordinates
{
public:
	Subordinates(int a, float A);
	Subordinates(int allfields);
	Subordinates();
	void input();
	void output();
	float averageseniority(int number);
	void set(Subordinates s);
	int getamount();
	Subordinates operator + (Subordinates s1);
	Subordinates& operator++(); //префиксный
	Subordinates operator++(int); //постфиксный
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int amount; //кол-во подчиненных
	float asos; //average seniority of subordinates - средний стаж подчиненных
};