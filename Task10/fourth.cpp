#include <iostream>
#include <vector>
using namespace std;
class oldmother
{
public:
    virtual void print() { cout << "oldMother" << endl; }
};
class olddaughter : public oldmother
{
public:
    virtual void print() { cout << "olddaughter" << endl; }
};
class oldson : public oldmother
{
public:
    virtual void print() { cout << "oldson" << endl; }
};

template <typename D>
class mother
{
public:
    void print()
    {
        static_cast<D *>(this)->talk();
    }
    void talk()
    {
        cout << "Mother" << endl;
    }
};

class daughter : public mother<daughter>
{
public:
    void talk()
    {
        cout << "daughter" << endl;
    }
};
class son : public mother<son>
{
public:
    void talk()
    {
        cout << "son" << endl;
    }
};

void talk(oldmother &lhs)
{
    lhs.print();
}

// template <typename left, typename right>
template <typename Someone>
void talk(Someone &s)
{
    cout<<"I'm ";
    s.print();
}

int main()
{
    cout << "Let's look on CRTP pattern" << endl;
    cout << "At first, let's look on how we use virtual functions before" << endl;
    cout << "We have classes oldmother and it's children: olddaughter and oldson" << endl;
    cout << "They have virtual function print< via which they can talk" << endl;
    olddaughter d;
    oldson s;
    talk(d);
    talk(s);
    cout << "But with CRTP we can parameterize our mother class with it's child and"
    << " learn it to call it's child functions without virtual functions at all :" << endl;
    daughter a;
    son b;
    talk(a);
    talk(b);
    cout <<"That's all. Goodbye !"<<endl;
    return 0;
}