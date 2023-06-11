#include <iostream>
#include <iomanip>
//Задача про перевод из системы в систему
using namespace std;

int main()
{
    int i = -1;
    float val = -1;
    const float TG = 0.0001;
    const float VsV = 0.00334;
    const float CF = 2998000000;
    cout << " 1.Tesla to Gauss \n 2.Volts to statVolts \n 3.Culon to Franklin\n"
         << "What do you choose (1,2,3) ? " << endl;
    cin >> i;
    cout << "Enter value: ";
    cin >> val;
    cout << "Your value in SGSE is ";
    switch (i)
    {
    case (1):
        cout << val * TG << endl;
        break;
    case (2):
        cout << val * VsV << endl;
        break;
    case (3):
        cout << val * CF << endl;
        break;
    }
    return 0;
}
