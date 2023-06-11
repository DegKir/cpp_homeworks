#include<iostream>
using namespace std;

template <int a>
struct fib_calc
{
    static const int value = fib_calc<a-1>::value + fib_calc<a-2>::value ;
};

template <>
struct fib_calc<0>
{
    static const int value = 0;
};

template <>
struct fib_calc<1>
{
    static const int value = 1;
};

template <>
struct fib_calc<2>
{
    static const int value = 1;
};

int main()
{
    cout<<"Hello, this program is calculating fibonachi"<<endl;
    cout<<"fib_calc<0>::value "<< fib_calc<0>::value <<endl;
    cout<<"fib_calc<1>::value "<< fib_calc<1>::value <<endl;
    cout<<"fib_calc<2>::value "<< fib_calc<2>::value <<endl;
    cout<<"fib_calc<3>::value "<< fib_calc<3>::value <<endl;
    cout<<"fib_calc<4>::value "<< fib_calc<4>::value <<endl;
    cout<<"fib_calc<5>::value "<< fib_calc<5>::value <<endl;
    cout<<"fib_calc<6>::value "<< fib_calc<6>::value <<endl;
    cout<<"fib_calc<7>::value "<< fib_calc<7>::value <<endl;
    cout<<"Goodbye!"<<endl;
    return 0;
}
