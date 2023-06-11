#include <iostream>
#include <vector>

using namespace std;

/*Принимает ссылку на вектор, который
 надо отсортировать, начальную позицию 
 сортировки и конечную позицию сортировки*/
void Merge_sort(vector<int> &, int, int);

/*Принимает ссылку на вектор, который
 надо соединить, начальную позицию 
 первого соединяемого массива и 
 конечную позицию вторго соединяемого массива*/
void Merge_unite(vector<int> &, int, int);

int main()
{
    cout << "Give me the number of the numbers : ";
    int SIZE = 0;
    cin >> SIZE;
    vector<int> v(SIZE, 0);
    cout << "Give me the numbers itself !" << endl;
    for (auto &x : v)
        cin >> x;

    Merge_sort(v, 0, SIZE - 1);

    cout << endl
         << "There is your sorted massive, i found it !" << endl;
    for (auto x : v)
        cout << x << " ";
}

void Merge_sort(vector<int> &v, int left = 0, int right = 0)
{
    int i = left;
    int j = right;
    int mid = (right - left) / 2 + left;
    if (right - left > 1)
    {
        Merge_sort(v, left, mid);      //Рекурсия
        Merge_sort(v, mid + 1, right); //Рекурсия
    }
    Merge_unite(v, left, right); //Соединяет и упорядочивает два упорядоченных массива.
}

void Merge_unite(vector<int> &v, int left, int right)
{
    int mid = (right - left) / 2 + left;
    for (int i = mid + 1; i <= right; ++i)
    {
        int k = i;
        for (int j = k - 1; j >= left; j--)
        {
            if (v[k] < v[j])
            {
                swap(v[k], v[j]);
                k--;
            }
        }
    }
}