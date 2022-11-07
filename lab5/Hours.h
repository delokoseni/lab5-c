#pragma once
#include "Salary.h"
#include <string>
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
	Hours& operator++(); //����������
	Hours operator++(int); //�����������
	Hours operator + (Hours h2);
	void tofile(ofstream& file, string filename);
	void getfromfile(ifstream& file, string filename);
private:
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
};

