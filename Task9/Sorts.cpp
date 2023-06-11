#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template <typename T>
bool comp1(T lhs, T rhs)
{
    return lhs < rhs;
}

template <typename T>
bool comp2(T lhs, T rhs)
{
    return lhs > rhs;
}

template <typename T, int N>
void static_Merge_unite(T (&arr)[N], int left, int right, function<bool(int, int)> comparator);

template <typename T>
void dynamic_Merge_unite(T *, int left, int right, function<bool(int, int)> comparator);

template <typename T, int N>
void static_MergeSort(T (&arr)[N], int left, int right, function<bool(int, int)> comparator)
{
    int mid = (right - left) / 2 + left;
    if (right - left > 1)
    {
        static_MergeSort(arr, left, mid, comparator);      //Рекурсия
        static_MergeSort(arr, mid + 1, right, comparator); //Рекурсия
    }
    static_Merge_unite(arr, left, right, comparator); //Соединяет и упорядочивает два упорядоченных массива.
}

template <typename T>
void dynamic_MergeSort(T *arr, int left, int right, function<bool(int, int)> comparator)
{
    int mid = (right - left) / 2 + left;
    if (right - left > 1)
    {
        dynamic_MergeSort(arr, left, mid, comparator);      //Рекурсия
        dynamic_MergeSort(arr, mid + 1, right, comparator); //Рекурсия
    }
    dynamic_Merge_unite(arr, left, right, comparator); //Соединяет и упорядочивает два упорядоченных массива.
}

template <typename T, int N>
void static_Merge_unite(T (&arr)[N], int left, int right, function<bool(int, int)> comparator)
{
    int mid = (right - left) / 2 + left;
    for (int i = mid + 1; i <= right; ++i)
    {
        int k = i;
        for (int j = k - 1; j >= left; j--)
        {
            if (comparator(arr[k], arr[j]))
            {
                swap(arr[k], arr[j]);
                k--;
            }
        }
    }
}

template <typename T>
void dynamic_Merge_unite(T *arr, int left, int right, function<bool(int, int)> comparator)
{
    int mid = (right - left) / 2 + left;
    for (int i = mid + 1; i <= right; ++i)
    {
        int k = i;
        for (int j = k - 1; j >= left; j--)
        {
            if (comparator(arr[k], arr[j]))
            {
                swap(arr[k], arr[j]);
                k--;
            }
        }
    }
}

int main()
{
    cout << "This program sorts things via templates !" << endl;
    cout << "let's sort 4, 2, 3, 1 by ascending:" << endl;
    int A[] = {4, 2, 3, 1};
    static_MergeSort(A, 0, 3, [](int lhs, int rhs) { return comp1(lhs, rhs); });
    for (auto elem : A)
        cout << elem << " ";

    cout << endl
         << "let's sort 4.5, 2.5, 3.5, 1.5 by descending:" << endl;

    double B[] = {4.5, 2.5, 3.5, 1.5};
    static_MergeSort(B, 0, 3, [](double lhs, double rhs) { return comp2(lhs, rhs); });
    for (auto elem : B)
        cout << elem << " ";

    cout << endl
         << "Now let's do same things but with dynamic arrays" << endl;
    cout << "let's sort -4, -2, -3, -1 by ascending:" << endl;

    int *C = new int[4]{-4, -2, -3, -1};
    dynamic_MergeSort(C, 0, 3, [](int lhs, int rhs) { return comp1(lhs, rhs); });
    for (int i = 0; i < 4; i++)
        cout << C[i] << " ";
    cout << endl;

    cout << "let's sort -4.5, -2.5, -3.5, -1.5 by desscending:" << endl;
    double *D = new double[4]{-4.5, -2.5, -3.5, -1.5};
    dynamic_MergeSort(D, 0, 3, [](double lhs, double rhs) { return comp2(lhs, rhs); });
    for (int i = 0; i < 4; i++)
        cout << D[i] << " ";
    cout << endl;

    delete [] C;
    delete [] D;
    cout << "That's all. Goodbye!" << endl;

    return 0;
}