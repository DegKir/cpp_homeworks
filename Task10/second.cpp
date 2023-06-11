#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    Point(int x, int y) : x_(x), y_(y) {}
    int x_=0;
    int y_=0;
};


template <typename T,typename ...Args>
T* dynamic (Args ... args)
{
    T* p = new T{args...};
    return p;
}

int main()
{
    cout<<"Hello, i want to show how you can create new objects via super function <<dynamic>>"<<endl;
    cout<<"Let's create a point via super function <<dynamic>>:"<<endl;
    cout<<"let x be 2, let y be 4"<<endl;
    cout<<"Let's look on int now :"<<endl;
    auto A=dynamic<Point>(2,4);
    cout <<"x:"<<A->x_<<" y:"<<A->y_<<endl;
    cout<<"Let's now create a vector of integers with 1,2,3 via this function :"<<endl;
    auto B=dynamic<vector<int>>(1,2,3);
    cout<<"vector : "<<endl;
    for (auto const a: *B)
        cout<<a<<" ";
    cout<<endl<<"Everything works - Great !"<<endl<<"Goodbye!"<<endl;
    delete A;
    delete B;
    return 0;
}