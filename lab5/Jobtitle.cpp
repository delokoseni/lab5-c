#include "Jobtitle.h"
#include "checkfileextension.h"
#include "Subordinates.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//����������� ������ jobtitle �� ����� �����������
Jobtitle::Jobtitle(string jtitle, int hourlycost, Subordinates subs) {
	this->jtitle = jtitle;
	if (hourlycost >= 0)
		this->hourlycost = hourlycost;
	else {
		cout << "������� ������������ �������� hourlycost." << endl;
		this->hourlycost = 0;
	}
	this->subs = subs;
}

//����������� ������ jobtitle � ����� ����������
Jobtitle::Jobtitle(int allfields) {
	if (allfields >= 0) {
		jtitle = to_string(allfields);
		hourlycost = allfields;
		Subordinates s(allfields);
		subs = s;
	}
	else {
		cout << "������� ������������ �������� allfields." << endl;
		jtitle = "";
		hourlycost = 0;
		Subordinates s;
		subs = s;
	}
}

//����������� ������ jobtitle ��� ����������
Jobtitle::Jobtitle() {
	jtitle = "";
	hourlycost = 0;
	Subordinates s;
	subs = s;
}

//����� ��������� �������� 
void Jobtitle::set(Jobtitle j) {
	this->jtitle = j.jtitle;
	this->hourlycost = j.hourlycost;
	this->subs.set(j.subs);
}

//����� ����� ������ jobtitle
void Jobtitle::input() {
	string jtitle;
	int hourlycost;
	Subordinates subs;
	cout << "������� ���������: ";
	getline(cin, jtitle);
	cout << "������� ��������� ���� ������: ";
	cin >> hourlycost;
	subs.input();
	Jobtitle j(jtitle, hourlycost, subs);
	this->set(j);
}

//����� ������
void Jobtitle::output() {
	cout << "���������: " << jtitle << endl;
	cout << "��������� ���� ������: " << hourlycost << endl;
	subs.output();
}

//����� ��������� �������� � ��������
float Jobtitle::comparisonhc(float hcost) {
	float percent;
	float d = hourlycost;
	percent = d / (hcost / 100) - 100;
	return percent;
}

//����� ������������ ���������� ����������� ����������
int Jobtitle::getamount() {
	return subs.getamount();
}

//����� ��� �������������� ���������
void Jobtitle::editjtitle(string jtitle, string add) {
	int i;
	//��������� �����
	stringstream ss(this->jtitle);
	//������� ���������� ���� � ������
	int n = count(this->jtitle.begin(), this->jtitle.end(), ' ') + 1;
	string *words = new string[n];
	this->jtitle = "";
	for (i = 0; i < n; i++) {
		ss >> *(words + i);
	}
	for(i = 0; i < n; i++) {
		//���� ������ ����������
		if (!(*(words + i)).compare(jtitle)) {
			this->jtitle += add + " ";
		}
		this->jtitle += *(words + i) + " ";
	}
}

//���������� ��������� +
Jobtitle Jobtitle::operator + (Jobtitle j1){
	hourlycost += j1.hourlycost;
	subs = j1.subs + j1.subs;
	jtitle += j1.jtitle;
	return *this;
}

//���������� ��������� ++ ����������
Jobtitle& Jobtitle::operator++() {
	this->hourlycost += 1;
	this->subs++;
	return *this;
}

//���������� ��������� ++ �����������
Jobtitle Jobtitle::operator++(int) {
	Jobtitle temp = *this;
	++* this;
	return temp;
}

//����� ������ � ����
void Jobtitle::tofile(ofstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
	file << jtitle << "\t";
	file << hourlycost << "\t";
	subs.tofile(file, filename);
}

//����� ����� �� �����
void Jobtitle::getfromfile(ifstream& file, string filename) {
	if (!checkfileextension(filename))
		throw exception("������������ ������������ ���������� �����. ���������� ����������: \".txt\".\n");
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
		throw exception("� ����� ������������ ������ ��� ������  ��� ������� ������� ��� �����.\n");
	}

}