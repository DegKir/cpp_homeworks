#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

//Структура которая предаставляет нужную информацию о СЛУ
struct SYSTEM_OF_LINEAR_EQUATIONS
{
    SYSTEM_OF_LINEAR_EQUATIONS(string _name, double **_Matrix, int _SIZE) : name(_name), Matrix(_Matrix), SIZE(_SIZE)
    {
        cout << "SOLE " << name << " had been created !" << endl;
        Matrix = new double *[SIZE];
        for (int i = 0; i < SIZE; ++i)
            Matrix[i] = new double[SIZE];

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
                Matrix[i][j] = 0;
        }
    };

    SYSTEM_OF_LINEAR_EQUATIONS() : name("NO_NAME"), Matrix(0), SIZE(0)
    {
        cout << "SOLE " << name << " had been created !" << endl;
    };

    string name;
    double **Matrix; //Матрица основной системы
    int SIZE;        //Размер матрицы основной системы
    bool no_solutions = false;
    bool inf_solution = false;

    ~SYSTEM_OF_LINEAR_EQUATIONS()
    {
        for (int i = 0; i < SIZE; i++)
            delete[] Matrix[i];
        cout << "SOLE " << name << " is deleting now ..."
             << "SOLE deleted" << endl
             << "Now memory in save!" <<endl;
    }
};

void Matrix_print(SYSTEM_OF_LINEAR_EQUATIONS *);

int main()
{
    double **Matrix = 0;
    int SIZE = 3;
    cout<<"This program is all about Systems of Linear Equations"<<endl;
    cout<<"I will show you how you can interact with structure SOLE "
        <<"- Systems Of Linear Equations"<<endl; 
    SYSTEM_OF_LINEAR_EQUATIONS Equ("Current", Matrix, SIZE);
    cout << "I making SOLE now ..." << endl;
    Matrix = Equ.Matrix;
    cout << "Let's look on our main matrix:" << endl;
    Matrix_print(&Equ);
    cout << "Well, there's a lot of 0. I will change it " << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Please, enter raw №" << i + 1 << endl;
        for (int j = 0; j < SIZE; ++j)
            cin >> Matrix[i][j];
    }
    cout << "Let's look on it now" << endl;
    Matrix_print(&Equ);

    cout << "Now let's talk about solutions" << endl
         << "If no_solutions is " << Equ.no_solutions << " then you will see" << endl;
    if (!Equ.no_solutions)
    {
        cout << "There is solution !" << endl;
    }
    Equ.no_solutions = (!Equ.no_solutions);
    cout << "But if no_solutions is " << Equ.no_solutions << " then you will see" << endl;

    if (Equ.no_solutions)
    {
        cout << "There is no solutions" << endl;
    }
    cout << "This is the end" << endl
         << "Now you will see that we will clean all what need to be cleaned" << endl;
    return 0;
}

void Matrix_print(SYSTEM_OF_LINEAR_EQUATIONS *SOLE)
{
    for (int i = 0; i < SOLE->SIZE; ++i)
    {
        for (int j = 0; j < SOLE->SIZE; ++j)
        {
            cout << " " << SOLE->Matrix[i][j];
        }
        cout << endl;
    }
}