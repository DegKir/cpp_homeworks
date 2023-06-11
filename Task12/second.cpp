#include<iostream>
using namespace std;

template <int a>
struct fact_calc
{
    static const int value = a*fact_calc<a-1>::value;
};

template<>
struct fact_calc<0>
{
    static const int value = 1;
};

template<>
struct fact_calc<1>
{
    static const int value = 1;
};

template<int n,int k>
struct binominal_calc
{
    static const int value = fact_calc<n>::value/(fact_calc<n-k>::value*fact_calc<k>::value);
};

int main()
{
    cout<<"Hello, this program is calculating boniminal things:"<<endl;
    cout<<"C from 0 to 2 is "<< binominal_calc<2,0>::value <<endl;
    cout<<"C from 1 to 2 is "<< binominal_calc<2,1>::value <<endl;
    cout<<"C from 2 to 2 is "<< binominal_calc<2,2>::value <<endl;
    cout<<endl;

    cout<<"C from 0 to 4 is "<< binominal_calc<4,0>::value <<endl;
    cout<<"C from 1 to 4 is "<< binominal_calc<4,1>::value <<endl;
    cout<<"C from 2 to 4 is "<< binominal_calc<4,2>::value <<endl;
    cout<<"C from 3 to 4 is "<< binominal_calc<4,3>::value <<endl;
    cout<<"C from 4 to 4 is "<< binominal_calc<4,4>::value <<endl;
    cout<<endl;
    
    cout<<"Goodbye!"<<endl;
    return 0;
}
