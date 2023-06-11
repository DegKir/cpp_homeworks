#include <iostream>
#include <vector>
#include <string>
#include "SOLE.h"

using namespace std;

void say_hello();

int main()
{
    say_hello();
    using namespace std;
    return 0;
}

void say_hello()
{
    cout<<"I want to show you my class for Matrix and how it works"<<endl;
    cout<<"You can create Matrix with it's name, numbers and ortogonal bool state:"<<endl;
    cout<<"A('First Matrix',{{1,1},{1,1},false)"<<endl;
    MATRIX A("First Matrix",{{1,1},{1,1}},false);
    cout<<"function named .tell_me() tells you info about any matrix:"<<endl;
    cout<<"A.tell_me() :"<<endl<<endl;
    A.tell_me();
    cout<<endl<<"Also you can create noname Matrix with only numbers:"<<endl;
    MATRIX B({{2,2},{2,2}});
    cout<<"B({{2,2},{2,2}})"<<endl;
    B.tell_me();    
    cout<<"You can add one Matrix to another:"<<endl;
    cout<<"C = A + B"<<endl;
    MATRIX C = A + B;
    C.tell_me();
    cout<<"Also you can change ortogonal state:"<<endl;
    cout<<"Now ortogonal state is "<< A.is_ortogonal()<<endl;
    cout<<"A.state_ortogonal()"<<endl;
    A.state_ortogonal();
    cout<<"Now ortogonal state is "<<A.is_ortogonal()<<endl;
    cout<<"Goodbye!"<<endl;
}