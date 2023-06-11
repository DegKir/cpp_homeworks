#include <iostream>
#include <cmath>
//const int SIZE = 3;
using namespace std;

int main()
{
    const size_t SIZE = 3;
    float modifier;
    float Matrix[SIZE][SIZE] = {{3, 2, -5}, {2, -1, 3}, {3, 2, -5}};
//    int SIZE=3;
    // float *Matrix = new float [SIZE][SIZE];
    // float *Results = new float [SIZE];

    
    float Results[SIZE] = {-1, 13, 9};
    float Solution[SIZE] = {0, 0, 0};
    bool infinit_solution = false, no_solution = false;
    float zero_raw_test = 0;
    ;
    //  cout<<"PLEASE WORK PLEASE WORK";
    //Заполняем матрицу
    cout << "Give me Matrix of the system without column of results" << endl;
    for (size_t i = 0; i < SIZE; ++i)
    {
        cout << "Please, enter raw №" << i + 1 << endl;
        for (size_t j = 0; j < SIZE; ++j)
            cin >> Matrix[i][j];
    }

    //Заполняем дополнительный столбец результатов
    cout << "Please, enter column of Results:" << endl;
    for (size_t i = 0; i < SIZE; ++i)
        cin >> Results[i];

    //Приведение матрицы к верхне-треугольному виду
    for (size_t k = 0; k < SIZE; ++k)
    {
        for (size_t i = 0; i < SIZE; ++i)
        {
            if (Matrix[k][k] == 0)
            {
                swap(Matrix[k], Matrix[i]);
            }
            else
            {
                break;
            }
        }
        if (Matrix[k][k] == 0)
        {
            continue;
        }
        for (size_t i = k; i < SIZE; ++i)
        {
            modifier = Matrix[i][k];
            if (modifier == 0)
            {
                continue;
            }
            for (size_t j = k; j < SIZE; ++j)
                Matrix[i][j] = Matrix[i][j] / modifier;
            Results[i] = Results[i] / modifier;
        }

        for (size_t i = k + 1; i < SIZE; ++i)
        {
            if (Matrix[i][k])
            {
                for (size_t j = 0; j < SIZE; ++j)
                {
                    Matrix[i][j] = Matrix[i][j] - Matrix[k][j];
                }
                Results[i] = Results[i] - Results[k];
            }
        }
    }

    for (size_t i = 0; i < SIZE; ++i)
    {
        zero_raw_test = 0;
        for (size_t j = 0; j < SIZE; ++j)
            zero_raw_test += Matrix[i][j] * Matrix[i][j];
        if (zero_raw_test == 0)
        {
            if (Results[i] == 0)
                infinit_solution = true;
            else
                no_solution = true;
        }
    }

    if (no_solution)
    {
        cout << "OH NO !!! THERE IS NO SOLUTION !!!";
        return 0;
    }

    if (infinit_solution)
    {
        cout << "OH NO THERE IS TOO MUCH SOLUTIONS!!!";
        return 0;
    }

    //Обратная "развёртка" СЛУ
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
        cout << "x" << i << "= " << Results[i] << endl;
    // return 0;


    cout<<"BREAKING TESTS HA HAHAHAHAHAHAHA\n\n\n\n\n\n";

}