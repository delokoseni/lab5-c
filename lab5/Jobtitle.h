#pragma once
#include "Subordinates.h"
#include <string>
using namespace std;

class Hours;

class Jobtitle
{
	friend int normhcost(Hours hour, Jobtitle jtitle);
public:
	Jobtitle(string j, int h, Subordinates s);
	Jobtitle(int allfields);
	Jobtitle();
	void input();
	void output();
	float comparisonhc(float hcost);
	void set(Jobtitle j);
	int getamount();
	void editjtitle(string jtitle, string add);
	Jobtitle operator + (Jobtitle j1);
	Jobtitle& operator++(); //префиксный
	Jobtitle operator++(int); //постфиксный
private:
	string jtitle; //наименование должности
	int hourlycost; //стоимость часа работы
	Subordinates subs; //подчиненные
};
