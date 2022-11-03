#pragma once
#include "Salary.h"

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
private:
	int normal; //���-�� �����, ������������ �� �������
	int overtime; //���-�� �����, ������������ �����������
	int weekends; //��� - �� �����, ������������ � �������� ���
};

