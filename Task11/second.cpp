#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

template<typename T>
struct is_function : std::false_type{};


template <typename T, typename ... Args>
struct is_function <T(Args...)> : std::true_type
{
    using type = T;
};

int main()
{
    cout << "Hello this program checks if you give it function or not"<<endl;
    cout << "To example let's check type int"<<endl;
    cout << "is_function<int>::value " << is_function<int>::value<<" - not function"<<endl;
    cout << "is_function<int>::type " << typeid(is_function<int>::type).name()<<endl; 
    cout << "Let's now check type int(int) "<<endl;
    cout << "is_function<int(int)>::value " << (bool) is_function<int(int)>::value<<" - functnion"<<endl;
    cout << "is_function<int(int)>::type " << typeid(is_function<int(int)>::type).name()<<endl; 
    cout << "That's all. Goodbye !"<<endl;
    return 0;
}