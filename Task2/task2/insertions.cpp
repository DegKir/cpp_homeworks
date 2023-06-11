#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    cout << "How many elements ?" << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Please, enter elements" << endl;

    for( auto& x: v)
        cin>>x;


    for (size_t i = 0; i < n; ++i)
    {
        size_t j = i + 1;
        while (j-->1)
            if (v[j - 1] > v[j])
                swap(v[j - 1], v[j]);
    }

    for (auto& x: v)
        cout << x << " ";
}