#include<iostream>
using namespace std;
template <class T> struct remove_consttt{ typedef T type; };
template <class T> struct remove_consttt<T const>{ typedef T type; };

template<typename T>
struct add_consttt
{
    using type = const T;
};

int main()
{
    cout<<"Hello this is program about meta-function via which you can remove/add constants from/to types"<<endl;
    cout<<"To example, let's remove const from const int :"<<endl;
    cout<<"is_same<remove_consttt<const int>::type,int>::value "<<
        is_same<remove_consttt<const int>::type,int>::value <<", removed happily"<<endl;
    cout<<"Also let's try to add const to int:"<<endl;
    cout<<"is_same<add_consttt<int>::type,const int>::value "<<
        is_same<add_consttt<int>::type,const int>::value <<", added happily"<<endl;
    cout<<"That's all. Goodbye !"<<endl;
    return 0;
}
