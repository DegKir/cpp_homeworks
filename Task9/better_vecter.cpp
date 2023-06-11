#include <iostream>
#include <exception>
#include <stdexcept>
#include "bicycle_vector.h"
using namespace std;

int main()
{
    cout << "This is program about my brand new bicicle vector(bv)" << endl;
    cout << "Let's create bv with elements {0,1,2,3,4}" << endl;
    bicycle_vector<int> A{5};
    for (int i = 0; i < 5; i++)
        A[i] = i;
    for (auto &elem : A)
        cout << elem << " ";
    cout << endl;
    cout << "We can get it size" << endl;
    cout << "A.get_size() = " << A.get_size() << endl;
    cout << "Let me resize it to first 4 elements" << endl;
    A.resize(4);
    for (auto &elem : A)
        cout << elem << " ";
    cout << endl;
    cout << "A.get_size() = " << A.get_size() << endl;
    cout << "Let me add new element 7" << endl;
    A.pushback(7);
    for (auto &elem : A)
        cout << elem << " ";
    cout << "Try to take the 6th element:" << endl;
    try
    {
        cout << "trying to access element №10" << endl;
        A[10];
    }
    catch (const out_of_range &e)
    {
        cerr << e.what() << endl;
    }
    cout << "Goodbye !" << endl;
    return 0;
}