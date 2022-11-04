#pragma once
#include "Salary.h"
#include <fstream>
using namespace std;

class Hours
{
	friend int normhcost(Hours hour, Jobtitle jtitle);
public:
	Hours(int n, int o, int w);
	Hours(int allfields);
	Hours();
	void input();
	void output();
	int allhours();
	void set(Hours h);
	int hoursmoney(Jobtitle jt, Salary sal);
	Hours& operator++(); //префиксный
	Hours operator++(int); //постфиксный
	Hours operator + (Hours h2);
	void tofile(ofstream file);
private:
	int normal; //кол-во часов, отработанных по графику
	int overtime; //кол-во часов, отработанных сверхурочно
	int weekends; //кол - во часов, отработанных в выходные дни
};

