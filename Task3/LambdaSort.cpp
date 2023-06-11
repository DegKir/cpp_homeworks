#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void demonstration(void);

int main()
{
    demonstration();
    return 0;
}

void demonstration(void)
{
    cout << "Please, give me numbers of numbers :";
    int SIZE = 0;
    int i = -1;
    cin >> SIZE;
    vector<int> v(SIZE, 0);
    cout << "Please, give me the numbers :" << endl;
    for (auto &x : v)
        cin >> x;

    cout << "What sort do you want to do ?" << endl
         << "1.From small to big" << endl
         << "2.From big to small" << endl
         << "3.Even numbers first and after them not even" << endl;
    cin >> i;
    switch (i)
    {
    case (1):
        sort(v.begin(), v.end(), [](int a, int b) { return (a < b); });
        break;
    case (2):
        sort(v.begin(), v.end(), [](int a, int b) { return (a > b); });
        break;
    case (3):
        sort(v.begin(), v.end(), [](int a, int b) { return (a % 2 == 0); });
        break;
    };
    cout << "Here is your numbers, but SORTED : ";
    for (auto x : v)
        cout << x << " ";
}