#include <iostream>
#include "fraction.h"

Fraction::Fraction(): _up(0),_down(1){}
Fraction::Fraction(int up, unsigned int down): _up(up),_down(down){}
Fraction::~Fraction(){}
int Fraction::get_up()
{
    return _up;
}
unsigned int Fraction::get_down()
{
    return _down;
}
void Fraction::set_up(int up)
{
    _up=up;
    this->cut();
}
void Fraction::set_down(unsigned int down)
{
    _down=down;
    this->cut();
}
void Fraction::change_down(int new_down)
{
    _up=_up*(new_down/_down);
    _down=new_down;
}
void Fraction::cut()
{
    if(!_up)
    {
        _up=0;
        _down=1;
        return;
    } 
    unsigned int a,b;
    if (abs(_up) > (int)_down)
    {
        a=abs(_up);
        b=_down;
    }
    else
    {
        a = _down;
        b = abs(_up);
    }
    unsigned int mod = a;
    while(mod)
    {
        mod = a % b;
        if(mod)
        {
            a=b;
            b=mod;
        }
    }
    _up=(double)_up/(double)b;
    _down=(double)_down/(double)b;
}

std::ostream& operator<<(std::ostream& os, const Fraction number)
{
    os<<number._up<<"/"<<number._down;
    return os;
}
std::istream& operator>>(std::istream& os, Fraction& number)
{
    os>>number._up;
    os>>number._down;
    return os;
}

Fraction operator+(Fraction lhs, Fraction rhs)
{
    Fraction D;
    int share_down=lhs._down*rhs._down;
    lhs.change_down(share_down);
    rhs.change_down(share_down);
    D._down=share_down;
    D._up=rhs._up+lhs._up;
    D.cut();
    return D;
}

Fraction operator-(Fraction lhs, Fraction rhs)
{
    Fraction D2;
    D2._down = rhs._down;
    D2._up = - rhs._up;
    return lhs+D2;
}
Fraction operator*(Fraction lhs, Fraction rhs)
{
    Fraction D;
    D._down=rhs._down*lhs._down;
    D._up=rhs._up*lhs._up;
    D.cut();
    return D;
}
Fraction operator/(Fraction lhs, Fraction rhs)
{
    Fraction D;
    D._down = lhs._down*abs(rhs._up);
    D._up=((double)lhs._up*(double)rhs._down)*rhs._up/abs(rhs._up);
    D.cut();
    return D;
}
bool operator == (Fraction lhs, Fraction rhs)
{
    int share_down=lhs._down*rhs._down;
    lhs.change_down(share_down);
    rhs.change_down(share_down);
    return lhs._up==rhs._up ? true : false;
}

bool operator != (Fraction lhs, Fraction rhs)
{
    int share_down=lhs._down*rhs._down;
    lhs.change_down(share_down);
    rhs.change_down(share_down);
    return lhs._up!=rhs._up ? true : false;
}

bool operator <  (Fraction lhs, Fraction rhs)
{
    int share_down=lhs._down*rhs._down;
    lhs.change_down(share_down);
    rhs.change_down(share_down);
    return lhs._up<rhs._up ? true : false;
}

bool operator >  (Fraction lhs, Fraction rhs)
{
    int share_down=lhs._down*rhs._down;
    lhs.change_down(share_down);
    rhs.change_down(share_down);
    return lhs._up>rhs._up ? true : false;
}

Fraction Fraction::operator+=(Fraction& rhs)
{
    Fraction temp = *this + rhs;
    *this = temp;
    this->cut();
    return temp;
}
Fraction Fraction::operator-=(Fraction& rhs)
{
    Fraction temp = *this - rhs;
    *this = temp;
    this->cut();
    return temp;
}
Fraction Fraction::operator*=(Fraction& rhs)
{
    Fraction temp = *this * rhs;
    *this = temp;
    this->cut();
    return temp;
}
Fraction Fraction::operator/=(Fraction& rhs)
{
    Fraction temp = *this / rhs;
    *this = temp;
    this->cut();
    return temp;
}
Fraction& Fraction::operator++()
{
    _up+=_down;
    this->cut();
    return *this;
}
Fraction& Fraction::operator--()
{
    _up-=_down;
    this->cut();
    return *this;
}
Fraction Fraction::operator++(int)
{
    return ++(*this);
}
Fraction Fraction::operator--(int)
{
    return --(*this);
}

Fraction::operator double()
{
    return (double)_up/(double)_down;
}
