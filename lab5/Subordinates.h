#pragma once

class Subordinates
{
	friend Subordinates operator + (Subordinates s1, Subordinates s2);
public:
	Subordinates(int a, float A);
	Subordinates(int allfields);
	Subordinates();
	void input();
	void output();
	float averageseniority(int number);
	void set(Subordinates s);
	int getamount();
	Subordinates& operator++(); //����������
	Subordinates operator++(int); //�����������
private:
	int amount; //���-�� �����������
	float asos; //average seniority of subordinates - ������� ���� �����������
};