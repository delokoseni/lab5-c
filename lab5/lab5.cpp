#include "Employee.h"
#include "checkfileextension.h"
#include <conio.h>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int pos;
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
    string str = "Менеджер по продажам", fname = "text.txt";
    Jobtitle jt3(str, over, sub3);
    Employee emp, emp3(exp3, h3, jt3);
    ofstream file;
    file.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        file.open(fname, ios_base::app);
        emp3.tofile(file);
    }
    catch (const std::exception& ex1)
    {
        cout << ex1.what();
    }
    file.close();
    ifstream file1;
    file1.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        if (checkfileextension(fname)) {
            file1.open(fname);
            emp.getfromfile(file1);
            emp3.output();
            cout << endl;
            emp.output();
        }
    }
    catch (const ifstream::failure& ex2)
    {
        cout << ex2.what() << endl;
        cout << ex2.code() << endl;;
    }
    file1.close();
    return 0;
}