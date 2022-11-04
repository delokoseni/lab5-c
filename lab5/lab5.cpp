#include "Employee.h"
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int years = 10;
    int armyyears = 1;
    int materyears = 0;
    Experience exp3(years, armyyears, materyears);
    int norm = 120;
    int over = 10;
    int week = 10;
    Hours h3(norm, over, week);
    int a = 6;
    float b = 1.2;
    Subordinates sub3(a, b), sub;
    string str = "Менеджер";
    Jobtitle jt3(str, over, sub3);
    Employee emp, emp3(exp3, h3, jt3);
    ofstream file;
    file.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        file.open("text.txt");
        emp3.tofile(file);
    }
    catch (const std::exception&)
    {
        cout << "Ошибка открытия файла.\n";
    }
    file.close();
    ifstream file1;
    file1.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        file1.open("text.txt");
        emp.getfromfile(file1);
        emp3.output();
        emp.output();
    }
    catch (const std::exception&)
    {
        cout << "Ошибка открытия файла.\n";
    }
    file1.close();
    return 0;
}