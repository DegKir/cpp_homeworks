#include <iostream>
#include <string.h>

using namespace std;

//Класс client содержит своим подклассом класс cleint_info.
//Если объявить функцию дружественной к client_info, то она 
//будет иметь доступ только к её полям, но не полям внешнего класса
class client;

class accesable_info_client
{
public:
private:
    friend void client_info(client);
    string second_name = "ALYAEV ROMAN";
};

class client
{
public:
    client(){};
    accesable_info_client surname;

private:
    string very_secret_credit_card = "4908 1456 0987 6654";
};

void client_info(client person)  //Если расскоментить то смерть
{   
    cout << "Our stonks client is " << (person.surname.second_name) << endl;
    // cout << "you will never see this string"<<(person.very_secret_credit_card); 
}

void sey_hello();

int main()
{
    sey_hello();
    return 0;
}

void sey_hello()
{
    client Roma;
    cout << "This program tell us information about user" << endl;
    cout << "To example, our client ALYAEV ROMAN gave us his name and very secret credit card number" << endl;
    cout << "But our bank have very powerfull defend and ordinary functions can't get that very secret credit cart number" << endl;
    cout << "To example let's try to take his name :" << endl;
    client_info(Roma);
    cout << "But if someone very smart will change our code" << endl
         << "and will try to get acces to card number program will stop it work" << endl;
}