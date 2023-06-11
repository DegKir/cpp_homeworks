#include <iostream>
#include <string.h>

using namespace std;

enum class Months
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    Er
};

Months days_determ(int);
void print_days(Months);
int main()
{
    int n;
    Months month = Months::January;
    cout << "What month do you want to know about ?" << endl;
    cout << "1.January\n2.February\n3.March\n4.April\n5.May\n6.June\n7.July\n8.August"
         << endl<<"9.September\n10.October\n11.November\n12.December " << endl;
    cin >> n;
    month = days_determ(n);
    cout << "In your month ";
    print_days(month);
    cout << "day" << endl;
    cout << "Goodbye !";
    return 0;
}

Months days_determ(int n)
{
    switch (n)
    {
    case (1):
        return (Months::January);
    case (2):
        return (Months::February);
    case (3):
        return (Months::March);
    case (4):
        return (Months::April);
    case (5):
        return (Months::May);
    case (6):
        return (Months::June);
    case (7):
        return (Months::July);
    case (8):
        return (Months::August);
    case (9):
        return (Months::September);
    case (10):
        return (Months::October);
    case (11):
        return (Months::November);
    case (12):
        return (Months::December);
    default:
        return (Months::Er);
    }
}

void print_days(Months month)
{
    switch (month)
    {
    case (Months::January):
        cout << 31;
        break;
    case (Months::February):
        cout << 28;
        break;
    case (Months::March):
        cout << 31;
        break;
    case (Months::April):
        cout << 30;
        break;
    case (Months::May):
        cout << 31;
        break;
    case (Months::June):
        cout << 30;
        break;
    case (Months::July):
        cout << 31;
        break;
    case (Months::August):
        cout << 31;
        break;
    case (Months::September):
        cout << 30;
        break;
    case (Months::October):
        cout << 31;
        break;
    case (Months::November):
        cout << 30;
        break;
    case (Months::December):
        cout << 31;
        break;
    case (Months::Er):
        cout << "\n Wait, that is not a month !" << endl;
        break;
    }
}