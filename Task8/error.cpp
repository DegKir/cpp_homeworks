#include <iostream>
#include <cmath>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

void test_div_by_zero();
void test_out_of_range();
void test_overflow_error();
void test_domain_error();
double divide(double,double);
int summ(int,int);
double sqrt_with_check(double);

int main()
{   
    cout<<"Hello, i want to show how i can handle some errors !"<<endl;
    test_div_by_zero();
    test_out_of_range();
    test_overflow_error();
    test_domain_error();
    return 0;
}

void test_div_by_zero()
{
    cout<<"let's divide 5 by 0"<<endl; 
    double i = 0;
    try 
    {
        i = divide(5.0,i);
    }
    catch (const logic_error& e) 
    {
        cerr<< e.what() <<" :"<<endl<< "division by zero is forbidden"<<endl<<endl;
    }
}

void test_out_of_range()
{
    cout<<"Let's get out of vector range"<<endl;
    cout<<"Creating vector with lenght 5 "<<endl;
    vector<int> a(5);
    try
    {
        cout<<"trying to access element №10"<<endl;
        a.at(10);
    }
    catch (const out_of_range& e)
    {
        cerr<< e.what() <<" :"<<endl<<"Error !trying to acces element with index bigger then lenght of vector"<<endl<<endl;
    }

}

void test_overflow_error()
{
    cout<<"Let's try to plus to 2e9 and 2e9 within int type :"<<endl;
    int a = 2e9;
    int b = 2e9;
    try
    {
        summ(a,b);
    }
    catch(const overflow_error& e)
    {
        cerr<<e.what()<<" :"<<endl<<" result of operator+ is too big to be int"<<endl<<endl;
    }
}

void test_domain_error()
{
    cout<<"Let's try to take sqrt from -1 : "<<endl;
    double i = -1.0;
    try
    {
        sqrt_with_check(i);
    }
    catch(const domain_error& e)
    {
        cerr<<e.what()<<" :"<<endl<<"taking sqrt from negative number is forbidden"<<endl<<endl;
    }
}

double divide(double a, double b)
{
    if (b==0)
        throw logic_error(" Error !division by 0");
    return a/b;
}

int summ(int a, int b)
{
    if (pow(2,8*sizeof(int))/2-a<b)
    {
        throw overflow_error(" Error !too big");
    }
    return a+b;
}

double sqrt_with_check(double a)
{
    if (a < 0)
        throw domain_error("Error !sqrt from negative number");
    return sqrt(a);
}