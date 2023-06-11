#include <iostream>
using namespace std;

class Energy
{
public:
    Energy();
    Energy(double);
    void give_erg(double);
    void give_elV(double);
    void give_joul(double);
    double print_erg();
    double print_elV();
    double print_joul();

private:
    static const double joul_erg;
    static const double joul_elV;
    double joul;
};

const double Energy::joul_erg = 1e7;
const double Energy::joul_elV = 6.242e18;

int main()
{
    Energy particle;
    int choise;
    double my_energy;
    cout <<"Hello there !"<< endl<< "What measure unit do you want to enter ?" << endl;
    cout << "1.Jouls" << endl
         << "2.Ergs" << endl
         << "3.Electron-Volts" << endl;
    cin >> choise;
    cout << "Give me the nubmer itself!" << endl;
    cin >> my_energy;
    switch (choise)
    {
    case (1):
        particle.give_joul(my_energy);
        break;
    case (2):
        particle.give_erg(my_energy);
        break;
    case (3):
        particle.give_elV(my_energy);
        break;
    }
    cout << "What measure unit do you want to get ?" << endl;
    cout << "1.Jouls" << endl
         << "2.Ergs" << endl
         << "3.Electron-Volts" << endl;
    cin >> choise;
    switch (choise)
    {
    case (1):
        cout << particle.print_joul();
        break;
    case (2):
        cout << particle.print_erg();
        break;
    case (3):
        cout << particle.print_elV();
        break;
    }
    cout << endl
         << "Goodbye!" << endl;
    return 0;
}

Energy::Energy() : joul(0){};
Energy::Energy(double _joul) : joul(_joul){};

double Energy::print_erg()
{
    return (joul * joul_erg);
}

double Energy::print_elV()
{
    return (joul * joul_elV);
}

double Energy::print_joul()
{
    return joul;
}
void Energy::give_erg(double a)
{
    joul = a / joul_erg;
}
void Energy::give_elV(double a)
{
    joul = a / joul_elV;
}
void Energy::give_joul(double a)
{
    joul = a;
}
