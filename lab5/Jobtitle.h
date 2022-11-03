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
	Jobtitle& operator++(); //����������
	Jobtitle operator++(int); //�����������
private:
	string jtitle; //������������ ���������
	int hourlycost; //��������� ���� ������
	Subordinates subs; //�����������
};
