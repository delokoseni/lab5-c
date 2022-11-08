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
    int i, j;
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



    Employee arr2[2][2], arr1[3]{
        Employee(exp3++, h3++, jt3++),
        Employee(exp3++, h3++, jt3++),
        Employee(exp3++, h3++, jt3++)
    };



    ofstream file;
    file.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        file.open(fname, ios_base::app);
        for (i = 0; i < 3; i++) {
            arr1[i].tofile(file, fname);
        }
        file.close();
    }
    catch (exception& ex1)
    {
        cout << ex1.what();
    }



    ifstream file1;
    file1.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        file1.open(fname);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                arr2[i][j].getfromfile(file1, fname);
                arr2[i][j].output();
            }
        }
        file1.close();
    }
    catch (exception& ex2)
    {
        cout << ex2.what();
    }
    return 0;
}
