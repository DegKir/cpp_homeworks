#include <iostream>
#include <vector>
#include <string>
#include "SOLE.h"
using namespace std;

MATRIX::MATRIX() : name("NO NAME"), SIZE(0), Matrix{{0}}, ortogonal(false) {};
MATRIX::MATRIX(vector<vector<double>> _Matrix) :
    name("NO NAME"), SIZE(_Matrix.size()), Matrix(_Matrix), ortogonal(false) {};
MATRIX::MATRIX(string _name, vector<vector<double>> _Matrix, bool _ortogonal) : 
    name(_name), SIZE(_Matrix.size()), Matrix(_Matrix), ortogonal(_ortogonal) {};

void MATRIX::tell_me()
{
    cout << "Let me tell you about " << name << endl;
    cout << "Size is " << SIZE << endl;
    ortogonal ? cout<<"Matrix is ortogonal" : cout<< "Matrix isn't ortogonal"<<endl;
    cout << "Matrix itself is" << endl<<(*this)<< endl;
}

MATRIX MATRIX::operator+(MATRIX &b)
{
    vector<vector<double>> summ_matrix(SIZE);
    for (auto i = 0; i < SIZE; ++i)
        for (auto j = 0; j < SIZE; ++j)
            summ_matrix[i].push_back(Matrix[i][j] + b.Matrix[i][j]);
    return MATRIX("SUMM", summ_matrix,0);
}

bool MATRIX::is_ortogonal()
{
    return ortogonal;
}

void MATRIX::state_ortogonal()
{
    ortogonal = true;
}

void MATRIX::state_no_ortogonal()
{
    ortogonal = false;
}

ostream &operator<<(ostream &os, const MATRIX &mat)
{
    for (auto row : mat.Matrix)
    {
        for (auto elem : row)
            os << " " << elem << " ";
        os << endl;
    }
    return os;
}
