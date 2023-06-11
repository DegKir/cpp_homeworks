#include <iostream>

//Задача про две переменные которые надо поменять местами без третьей
using namespace std;

int main()
{
    int x = 5, y = 9;
    int i = sizeof(x);
    cout << "At the start x is " << x << " and y is " << y << endl;
    x = x ^ y;
    y = y ^ x;
    x = x ^ y;
    cout << "But in the end x is " << x << " and y is " << y << endl;
    return 0;
}
