#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

/*Принимает два аргумента типа строка.
И один аргумент ссылки на строку
Первые два это изначальные последовательности.
В третью запишется их общая подпоследовательность*/
bool common_subsequence(string a,string b,string &result)
{
    vector<char> com_sub(max(a.size(), b.size())); //Итоговая строчка

    //ABStract_Matrix - основная матрица в которую будут записаны длинны различных подпосл.
    //Инициализируется нулями ( узнал умное слово конструктор )
    vector<vector<int>> ABS_Matrix(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i < a.size() + 1; ++i)
    {
        for (int j = 1; j < b.size() + 1; ++j)
        {
            if (a[i - 1] == b[j - 1])
                ABS_Matrix[i][j] = ABS_Matrix[i - 1][j - 1] + 1;
            else
                ABS_Matrix[i][j] = max(ABS_Matrix[i - 1][j], ABS_Matrix[i][j - 1]);
        }
    }

    int j = b.size() - 1;
    int i = a.size() - 1;

    //Разворачиваем ABS_Matrix в обратную сторону и ищем нужную п-ть
    while ((j >= 1) && (i >= 1))
    {
        if (a[i] != b[j])
        {
            if (ABS_Matrix[i - 1][j] < ABS_Matrix[i][j])
                j--;
            else
                i--;
        }
        else
        {
            com_sub.push_back(a[i]);
            j--;
            i--;
        }
    }

    if(com_sub[0]=='\000')
        return 0;

    reverse(com_sub.begin(), com_sub.end());    //Последовательность надо перевернуть
    for(auto x:com_sub)                         //потому что мы шли задом наперёд
        result.push_back(x);         

    return 1;
}

int main()
{
    string a = "000000";
    string b = "000000";
    string result= "";
    cout << "Hello there !" << endl
         << "Give me two string and i will return you their longest common subsequence " << endl;
    cout << "First string: ";
    cin >> a;
    cout << "Second string: ";
    cin >> b;

    if (common_subsequence(a,b,result)==0)
    {
        cout<<"THere is no common subsequence at all !";
        return 0;
    }

    cout << "I have found the longest common subsequence !" << endl<< "THERE IT IS : "
            <<result<<endl;
    return 0;
}