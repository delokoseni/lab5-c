#pragma once
#include "Experience.h"
#include "Jobtitle.h"

class Salary
{
    friend Salary operator + (Salary s1, Salary s2);
public:
    Salary(int overtimecost, int weekendcost, int exppercent, int subspercent, bool expstatus, \
        bool subsstatus);
    Salary(int allfields);
    Salary();
    void set(Salary salary);
    void input();
    void output();
    int overtimeweekends(int overtime, int weekends);
    int allmoney(int salary, Experience exp, Jobtitle jt);
    Salary& operator++(); //префиксный
    Salary operator++(int); //постфиксный
private:
    int overtimecost; //Процент увеличения оплаты сверхурочных часов 
    int weekendcost; //Процент увеличения оплаты часов отработанных в выходные
    int exppercent; //Процент увеличения оплаты за стаж
    int subspercent; //Процент увеличения оплаты за наличие подчененных
    bool expstatus; //Учет стажа
    bool subsstatus; //Учет наличия подчиненных
};

