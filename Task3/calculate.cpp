#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;
/*Получает два числа типа double и
 ссылку на функцию-вычисление типа std::function, которая принимает
  два числа типа double и возвращает число типа double.
  Возвращает результат использования первых двух double функцией*/
// double calculate(double a, double b, double (*)(double, double));
double calculate(double a, double b, function<double(double, double)>);

void demonstration(void);

int main()
{
    demonstration();
    return 0;
}

double calculate(double a, double b, function<double(double, double)> F)
{
    cout << "Your answer is " << F(a, b) << endl;
    ;
}

void demonstration(void)
{
    vector<function<double(double, double)>> v;

    v.push_back([](double a, double b) { return a + b; });
    v.push_back([](double a, double b) { return a * b; });
    v.push_back([](double a, double b) { return sqrt(a * a + b * b); });

    int i;
    double a;
    double b;
    cout << "Give me the numbers ! " << endl;
    cin >> a;
    cin >> b;
    cout << "I will do this operations with your numbers :" << endl
         << "1.Summ" << endl
         << "2.Multiply" << endl
         << "3.sqrt(a^2+b^2)" << endl;

    for (int i = 0; i < v.size(); ++i)
    {
        calculate(a, b, v[i]);
    }
}
