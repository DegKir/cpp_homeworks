#include <iostream>
using namespace std;

int main()
{
    int i=0;
    char str[]="ABCD";
    for(i;str[i]!='\0';i++){}
    cout<<i;

    int j=0;
    while(str[++j]!='\0'){}
    cout<<j;
    return 0;
}
