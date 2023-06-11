#include <iostream>
using namespace std;

template <typename T>
int spec_sizeof_old( T first)
{
    return sizeof(T);
}

template <typename T, typename ... Args>
int spec_sizeof_old( T first, Args ... args)
{
    return (sizeof(T)+spec_sizeof_old(args...));
}


template <typename ...Args>
int spec_sizeof (Args ... args)
{
    static counter = 0;
    return (...+sizeof(args));
}

int main()
{
    cout<<"Hello ! This program is calculating the size of thins that you put in"<<endl;
    cout<<"To example size of (1,2.0,c) = "<<spec_sizeof_old(1,2.0,'c')<<endl;
    cout<<"Also size of (1,false,true, 100000000000) = "<< spec_sizeof(1,false,true,100000000000)<<endl; 
    cout<<"That's all. Goodbye !";
    return 0;
}