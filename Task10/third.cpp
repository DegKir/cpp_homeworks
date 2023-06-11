#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename... Args>
void shadow_call(T arg, Args... args)
{
    arg(args...);
}

int Sum(int a, int b)
{
    cout << "Sum of " << a << " and " << b << " is " << a + b << endl;
    return a + b;
}

int main()
{
    cout << "Hello, i want to show how you can call functions via super function <<shadow_call>>" << endl;
    cout << "let's try to load in shadow_call lambda function which prints <<Hello world>>" << endl;
    shadow_call([]() -> void { cout << "Hello world" << endl; });
    cout << "let's try to load in shadow_call lambda function which prints that it's very heppy to wark" << endl;
    shadow_call([]() -> void { cout << "I'M WORKING! YEAH!" << endl; });
    cout << "let's try to load in shadow_call function which summing two integers:" << endl;
    shadow_call(Sum, 1, 2);
    cout << "That's all. Goodbye!";
    return 0;
}