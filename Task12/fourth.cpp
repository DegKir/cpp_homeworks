#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
using std::cout;
using std::endl;

struct Point
{
    int x=0;
    int y=0;
};

template<typename T>
struct is_comparable
{
    template<typename A>
    static decltype(A()>A()) detect(const A& a){return 0;}

    template<typename ...>
    static int detect(...){return '0';}

    constexpr static bool value = 
    (sizeof(detect<T>(0)) == sizeof(char));
};

template <typename T>
std::enable_if_t<is_comparable<T>::value, void> compare(const T&, const T&)
{
    std::cout << " The first one is better ! or the second one ..." << std::endl;
}

template <typename T>
std::enable_if_t<!is_comparable<T>::value, void> compare(const T&, const T&) 
{
    std::cout << "Axiom of the Escobar, they are not comparable." << std::endl;
}

int main()
{
    cout<<"Hello this program is looking into your type and say if it comparable or no"<<endl;
    
    cout<<"is_comparable<int>::value "<<is_comparable<int>::value<<endl;
    cout<<"is_comparable<std::vector<int>>::value "<<is_comparable<std::vector<int>>::value<<endl;
    cout<<"is_comparable<double>::value "<<is_comparable<double>::value<<endl;
    cout<<"is_comparable<std::string>::value "<<is_comparable<std::string>::value<<endl;
    cout<<"is_comparable<Point>::value "<<is_comparable<Point>::value<<endl;

    cout<<"compare<int>(5,4)";
    compare<int>(5,4);
    cout<<"compare<Point>(Point(),Point()) "; 
    compare<Point>(Point(),Point());

    cout<<"Goodbye!"<<endl;
    return 0;
}