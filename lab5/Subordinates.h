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
	Subordinates& operator++(); //����������
	Subordinates operator++(int); //�����������
	void tofile(ofstream& file);
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};