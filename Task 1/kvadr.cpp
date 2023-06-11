#include <iostream>
#include <iomanip>
#include <cmath>
//Задча про решение квадратного уравнения

using namespace std;

int main()
{
    float a = 0, b = 0, c = 0, D;
    cout << "ax^2+bx+c=0 " << endl;
    cout << "Give me a" << endl;
    cin >> a;
    cout << "Give me b" << endl;
    cin >> b;
    cout << "Give me c" << endl;
    cin >> c;
    if(a==0)
    {
        cout<<"x is "<<-c/b;
        if(b==0)
            cout<<"there is no solution";
        return 1;
    }
    D = b * b - 4 * a * c;
    if (D == 0)
    {
        cout << "x =" << -b / (2 * a) << endl;
        return 0;
    }
    if (D > 0)
    {
        cout << "x1 = " << ((-b) + sqrt(D)) / (2 * a) << endl
             << "x2 = " << ((-b) - sqrt(D)) / (2 * a) << endl;
        return 0;
    }
    cout << "There is no solution";
    return 0;
}
