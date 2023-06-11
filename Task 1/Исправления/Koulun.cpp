#include <iostream>
#include <iomanip>
//Задача про планету Коулун и перевод цен
using namespace std;

int main()
{
    char name[10] = "none";                 //Эта переменная нужна, в неё я пишу имя
    bool cashback = false;
    const char PRICE[] = "Price";
    const char CASH_BACK[] = "Has_cash_back";
    const char MAX_TEMP[] = "Max temperature";

    int price = -1;
    int temperature = -1;
    int wideness = 35;

    cout << "Product's name: ";
    cin >> name;
    cout << "\nProduct's price: ";
    cin >> price;
    cout << "\nIs cash-back availavle for this product? (true/false): ";
    cin >> boolalpha >> cashback;
    cout << "\nMaximum storing temperature : ";
    cin >> temperature;
    cout.fill('.');
    cout << endl
         << name << endl;
    cout << PRICE << setw(wideness - sizeof(PRICE) - 8) << '.' << setfill('0') << setw(8) << hex << uppercase << price << dec << endl;
    cout.fill('.');
    cout << CASH_BACK << setw(wideness - sizeof(CASH_BACK)) << boolalpha << cashback << endl;
    cout << MAX_TEMP << setw(wideness - sizeof(MAX_TEMP)) << showpos << temperature << endl;
    cin >> name;
    return 0;
}
