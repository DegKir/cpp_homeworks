#include <iostream>
#include <vector>

using namespace std;

class GoodClass
{
private:
    int SIZE;
    int* array;
    vector<int> v;
public:
    GoodClass():SIZE(0),array(new int[0]),v(vector<int>(0)){cout<<"created"<<endl;}
    ~GoodClass()
    {
        delete [] array;
        cout<<"destroyed"<<endl;
    };                               
    GoodClass(const GoodClass &other):SIZE(other.SIZE), array(new int[SIZE])
    {
        cout<<"created and copyed"<<endl;
        for (int i=0;i<SIZE;++i)
            array[i]=other.array[i];
        for (auto const elem:other.v)
            v.push_back(elem);
    }

    GoodClass &operator=(const GoodClass &other)
    {
        cout<<"copyed"<<endl;
        if(this==&other)
        {
            return *this;
        }
        delete []array;
        SIZE=other.SIZE;
        array = new int[SIZE];
        v.clear();
        for(int i=0;i<SIZE;++i)
            array[i]=other.array[i];
        for (auto const elem:other.v)
            v.push_back(elem);  
        return (*this);
    }          

    GoodClass(GoodClass&& other) :array(other.array), SIZE(other.SIZE), v(move(other.v))
    {
        other.array=nullptr;
    }
    GoodClass& operator=(GoodClass&& other)
    {
        cout<<"moved"<<endl;
        if(this==&other)
        {
            return *this;
        }
        delete [] array;
        array = other.array;
        other.array = nullptr;
        return *this;
    }

    int* adress()
    {
        return array;
    }
};

GoodClass generateItem()
{
    GoodClass D;
    return D;
}

void say_hello();

int main()
{
    // cout<<"Let's talk about copying"<<endl;
    // cout<<"A is object of GoodClass"<<endl;
    // GoodClass A;
    // cout<<"Adress in A = "<<A.adress()<<endl;
    // cout<<"B(A)"<<endl;
    // GoodClass B(A);  
    // cout<<"Adress in B = "<<B.adress()<<endl;
    // cout<<"C"<<endl;
    // GoodClass C;
    // cout<<"C=A"<<endl;
    // C=A;
    // cout<<"Adress in C = "<<C.adress()<<endl;
    // cout<<"They all are different !"<<endl;
    // cout<<"Now let's look on moving"<<endl;
    // cout<<"D is object of GoodClass"<<endl;    
    // GoodClass D;
    // cout<<"Now let's change D with moving function : "<<endl;
    // D = generateItem();
    // cout<<"We saw that some object was destroyed. It was in-function variable, but it's was transmitted in D"<<endl;
    // cout<<"Now we will destroy everything"<<endl;
    say_hello();
    return 0;
}

void say_hello()
{
    cout<<"Let's talk about copying"<<endl;
    cout<<"A is object of GoodClass"<<endl;
    GoodClass A;
    cout<<"Adress in A = "<<A.adress()<<endl;
    cout<<"B(A)"<<endl;
    GoodClass B(A);  
    cout<<"Adress in B = "<<B.adress()<<endl;
    cout<<"C"<<endl;
    GoodClass C;
    cout<<"C=A"<<endl;
    C=A;
    cout<<"Adress in C = "<<C.adress()<<endl;
    cout<<"They all are different . So there is no flat copying !"<<endl;
    cout<<"Now let's look on moving"<<endl;
    cout<<"D is object of GoodClass"<<endl;    
    GoodClass D;
    cout<<"Now let's change D with moving function : "<<endl;
    D = generateItem();
    cout<<"We saw that in-function variable was destroyed"<<endl
        <<"But it's was transmitted via moving in D"<<endl;
    cout<<"Now we will destroy everything"<<endl;
}
