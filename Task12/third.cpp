#include <iostream>
using namespace std;

constexpr long long int Factorial(int n) { return n ? (n * Factorial(n - 1)) : 1; }


constexpr double emak()
{
    constexpr int n=66;
    double s = 1.0;
    for (int i=1;i<n;i++)
    {
        s+=1/static_cast<double>(Factorial(i));
    }
    return s;
}

int main()
{
    cout<<"Hello, this program is approximating e number via Taylor series"<<endl;
    cout<<"e is "<<emak()<<endl;
    cout<<"Goodbye!"<<endl;
    return 0;
}