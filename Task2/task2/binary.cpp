#include <iostream>
#include <vector>

using namespace std;

//Принимает ссылку на vector<int> и ключ int. Возвращает true если ключ входит в вектор, false если нет.
bool binary_search(vector<int> &, int) ;

int main()
{
    int n=0;
    int key;

    cout << "How many keys ?" << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Please, enter keys IN ORDER FROM SMALL TO BIG" << endl;
    for (auto& x:v)
        cin >> x;

    
    cout << "What key do you want to find ? ";
    cin >> key;
    cout << (binary_search(v,key) ? "Yes this key is there" : "No, there is no this key"); 

    return 0;
}   

bool binary_search(vector<int> &v, int key) 
{
    int left,right/*,SIZE*/,m;
    // SIZE=v.size();
    left = 0;
    right = v.size();

    while (right >= left)/* && (!founded))*/
    {
        m = (right + left) / 2;
        if (key == v[m])
            // founded = 1;
            return(true);
        if (key > v[m])
            left = m + 1;
        else
            right = m - 1;
    }
    return(false);
}