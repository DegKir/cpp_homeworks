#include <iostream>
using namespace std;

struct ttime
{
    ttime() : milliseconds(0), minutes(0), hours(0), days(0), months(0), years(0)
    {
        //
    };
    unsigned milliseconds : 10;
    unsigned seconds : 6;
    unsigned minutes : 6;
    unsigned hours : 5;
    unsigned days : 5;
    unsigned months : 4;
    unsigned years : 8;
};
void time_print(ttime);
void time_log(ttime *);
int main()
{
    ttime log;
    cout << "I will say you time, when this program has been created :" << endl;
    ;
    time_log(&log);
    cout << "This program has been created: " << endl;
    time_print(log);
    return 0;
}

void time_print(ttime now)
{
    cout << "Date is " << now.days << "." << now.months << "." << now.years + 1970 << endl;
    cout << "Time is " << now.hours << ":" << now.minutes << ":" << now.seconds << "  ms:" << now.milliseconds << endl;
}

void time_log(ttime *now)
{
    now->years = 50;
    now->months = 9;
    now->days = 26;
    now->hours = 23;
    now->minutes = 24;
    now->seconds = 24;
    now->milliseconds = 75;
}