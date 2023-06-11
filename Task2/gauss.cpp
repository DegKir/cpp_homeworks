#include <iostream>
#include <cmath>

using namespace std;

//Структура которая предаставляет нужную информацию о СЛУ
struct SYSTEM_OF_LINEAR_EQUATIONS{
 	float **Matrix;                 //Матрица основной системы
    float *Results;                 //Дополненный столбец
    int SIZE;                     //Размер матрицы основной системы
    int problem_with_solutions;   /*Параметр. 0 если есть решения
                                                1 если их бесконечно много
                                                2 если их совсем нет */
};


//Принимает указатель на структуру СЛУ. Записывает в матрицу введённое пользоваталем значение
void Making_New_Matrix(SYSTEM_OF_LINEAR_EQUATIONS*);

//Принимает указатель на структуру СЛУ. Приводит матрицу к треугольному виду и задаёт параметр 0,1,2
void Gauss_on_Matrix(SYSTEM_OF_LINEAR_EQUATIONS*);

//Принимает указатель на структуру СЛУ.Выводит решение СЛУ
void Print_Solution(SYSTEM_OF_LINEAR_EQUATIONS*);



int main()
{
    struct SYSTEM_OF_LINEAR_EQUATIONS SOLE;   
    struct SYSTEM_OF_LINEAR_EQUATIONS *POINTER_SOLE;    //Здесь находится основная СЛУ
    POINTER_SOLE = &SOLE; 
    cout<<"Size of the Matrix = ";
    cin >> POINTER_SOLE->SIZE;
    int SIZE = POINTER_SOLE->SIZE;
    float **Matrix;
    float *Results;
    int problem_with_solutions=0;

    Matrix = new float *[SIZE];
    for (int i = 0; i < SIZE; ++i)
        Matrix[i] = new float[SIZE];
    Results = new float[SIZE];

    POINTER_SOLE -> Matrix = Matrix;
    POINTER_SOLE -> Results = Results;
    POINTER_SOLE -> problem_with_solutions = problem_with_solutions;
    POINTER_SOLE -> SIZE = SIZE;

    
    Making_New_Matrix(POINTER_SOLE);
    Gauss_on_Matrix(POINTER_SOLE);
    Print_Solution(POINTER_SOLE);


    delete[] Results;
    for (int i = 0; i < SIZE; i++)
        delete[] Matrix[i];

    return 0;
}

void Making_New_Matrix(SYSTEM_OF_LINEAR_EQUATIONS *POINTER_SOLE)
{
    float **Matrix = POINTER_SOLE -> Matrix;
    float *Results = POINTER_SOLE -> Results;
    int SIZE = POINTER_SOLE -> SIZE;
    cout << "Give me Matrix of the system without column of results" << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Please, enter raw №" << i + 1 << endl;
        for (int j = 0; j < SIZE; ++j)
            cin >> Matrix[i][j];
    }

    cout << "Please, enter column of Results:" << endl;
    for (size_t i = 0; i < SIZE; ++i)
        cin >> Results[i];
}

void Gauss_on_Matrix(SYSTEM_OF_LINEAR_EQUATIONS *POINTER_SOLE)
{ 
    float **Matrix = POINTER_SOLE -> Matrix;
    float *Results = POINTER_SOLE -> Results;
    int SIZE = POINTER_SOLE -> SIZE;

    //Цикл приводит матрицу к верхне-треугольному виду
    for (int k = 0; k < SIZE; ++k)
    {   
        for (int i = 0; i < SIZE; ++i)          //Если диагональный элемент матрицы ноль,то
        {                                       //меняем со следующей строкой.
            if (Matrix[k][k] == 0)
            {
                swap(Matrix[k], Matrix[i]);
                swap(Results[k], Results[i]);
            }
            else
                break;
        }
        if (Matrix[k][k] == 0)                  //Если перебрали все строки а элемент всё ещё 0
            continue;                           //то просто оставим эту строку таковой
                                                //и перейдём на следующую итерацию

        for (int i = k; i < SIZE; ++i)          //Приведение к единице 
        {
            float modifier = Matrix[i][k];      
            if (modifier == 0)
            {
                continue;
            }
            for (int j = k; j < SIZE; ++j)
                Matrix[i][j] = Matrix[i][j] / modifier;
            Results[i] = Results[i] / modifier;
        }

        for (size_t i = k + 1; i < SIZE; ++i)  //Вычитание строк
        {
            if (Matrix[i][k])
            {
                for (size_t j = 0; j < SIZE; ++j)
                    Matrix[i][j] = Matrix[i][j] - Matrix[k][j];
                Results[i] = Results[i] - Results[k];
            }
        }
    }
    for (size_t i = 0; i < SIZE; ++i)           //складываем квадраты всех элементов строки
    {                                           //и смотрим, является ли она нулевой
        float zero_raw_test = 0;               
        for (size_t j = 0; j < SIZE; ++j)
            zero_raw_test += Matrix[i][j] * Matrix[i][j];
        if (zero_raw_test == 0)
        {
            if (Results[i] == 0)
            {
                if(POINTER_SOLE->problem_with_solutions!=2)
                    POINTER_SOLE -> problem_with_solutions = 1;//infinitum
            }
            else
            {
                POINTER_SOLE -> problem_with_solutions = 2;//no NEED ADVENTAGE OF 2 OVER 1
            }
        }
    }    
}

void Print_Solution(SYSTEM_OF_LINEAR_EQUATIONS *POINTER_SOLE)
{
    float **Matrix = POINTER_SOLE -> Matrix;
    float *Results = POINTER_SOLE -> Results;
    int SIZE = POINTER_SOLE -> SIZE;
    int problem_with_solutions = POINTER_SOLE -> problem_with_solutions;

    float *Solution;
    Solution = new float[SIZE];
    switch (problem_with_solutions)
    {
    case (0):
        for (int i = int(SIZE - 1); i >= 0; --i)
        {
            for (size_t j = i + 1; j < SIZE; j++)
            {
                if (Solution[i] != 0)
                    Results[i] = Results[i] - Solution[j] * Matrix[i][j];
            }
            Solution[i] = Results[i];
        }

        cout << endl
             << "I have the solution !" << endl;

        for (size_t i = 0; i < SIZE; ++i)
            cout << "x" << i + 1 << "= " << Results[i] << endl;
        break;

    case (1):
        cout << "There is an infinit amount of solutions!!!";
        break;
    case (2):
        cout << "There is no solutions at all !";
        break;
    }
    delete[] Solution;
}