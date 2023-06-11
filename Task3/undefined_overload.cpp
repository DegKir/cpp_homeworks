#include <iostream>
#include <string>
using namespace std;

void f1(bool a, int i)
{
    cout << "f2";
}

void f1(int i, double d)
{
    cout << "f1";
}

void f2(double d, char c)
{
    cout << "Haha";
}

void f2(int i, int c)
{
    cout << "too easy!";
}

void f3(double d, int i = 0)
{
    cout << "int,double";
}

void f3(double d)
{
    cout << "There is only double";
}

void f4(long i, string = "noneklmn")
{
    cout << "this is string";
}

void f4(int i, char[])
{
    cout << "list of chars!";
}

int main() //Раскоменчивание этих функций ни к чему хорошему не ведёт
{
    //    f1(1,0);      //не может нормально различить bool и int
    //    f2(2.0, 56);  //не может решить, нужно ли приводить 2.0 к int или 56 к char
    //    f3(5.0);      //не понимает к функции с каким количеством параметров я обращаюсь

    //    f4(2,"pepe");   //приводить к char очень не хочет но всё равно это делает
    //компилятор напрямую неопределённость не пишет
    //и от того ещё страшнее
    return 0;
}
