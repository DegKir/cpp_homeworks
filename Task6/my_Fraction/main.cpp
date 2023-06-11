#include<iostream>
#include"fraction.h"

void say_hello();

int main()
{
    say_hello();
    return 0;
}

void say_hello()
{
    using namespace std;
    cout<<"Let me introduce my fraction class"<<endl;
    cout<<"Let's create Fraction A"<<endl;
    Fraction A;
    Fraction D;
    cout<<"Let's use std::cin to fill it up with numbers"<<endl;
    cout<<"Give me the up number and the down number of A: "<<endl;
    cin>>A;
    cout<<"So, let's look on it via std::cout"<<endl;
    cout<<A<<endl;
    cout<<"Now let's look on operations"<<endl;
    Fraction B;
    cout<<"Give me another fraction B :"<<endl;
    cin>>B;
    cout<<"A + B = "<<A+B<<endl;
    cout<<"It is also possible to use += instead of +"<<endl;
    D=A;
    D+=B;
    cout<<"A+=B. A = "<<D<<endl;
    cout<<"A-B = "<<A-B<<endl;
    cout<<"A*B = "<<A*B<<endl;
    cout<<"A/B = "<<A/B<<endl;
    cout<<"Now lets' compare them !"<<endl;
    if(A==B){cout<<"They are the same"<<endl;};
    if(A>B){cout<<"First is bigger"<<endl;};
    if(A<B){cout<<"Second is bigger"<<endl;};
    if(A!=B){cout<<"They are not the same"<<endl;};
    cout<<"Let's make one of them into double ! (double)A = "<< double(A)<<endl;
    cout<<"Goodbye!"<<endl;
}
