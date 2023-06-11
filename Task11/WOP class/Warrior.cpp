#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Warrior.h"

Weapon::Weapon(){}
Weapon::Weapon(double damage,double range,string name):damage_(damage), range_(range), name_(name){}
Warrior::Warrior(){}
Warrior::Warrior(double hp) : hp_(hp) {};
Weapon Warrior::get_weapon(){return right_hand;}
void Warrior::set_weapon(Weapon weapon ){right_hand = weapon;}
double Warrior::get_hp ()
{
    return hp_;
}
void Warrior::set_hp (double new_hp)
{
    hp_= new_hp;
}
void Warrior::help_print()
{
    cout<<"Equiped with "<< this->get_weapon().name_
        <<" which dealt " << this->get_weapon().damage_ <<" damage"<<endl;
    cout<<" hp = "<< hp_ ;
}
bool Warrior::is_dead()
{
    return this->hp_ < 0 ? 1 : 0;
}
void Warrior::deading(){}
Warrior::~Warrior(){}

Knight::Knight() : Warrior(10.0){}

void Knight::strike(Warrior & target)
{
    target.set_hp(target.get_hp()-this->get_weapon().damage_);
    cout<<"Knight dealt "<< this->get_weapon().damage_ <<" damage with "<< this->get_weapon().name_<<endl;
    if (target.is_dead()) 
        target.deading();
}
void Knight::state()
{
    cout<<"state of Knight : ";
    cout<<"Equiped with "<< this->get_weapon().name_
        <<" which dealt " << this->get_weapon().damage_ <<" damage"<<endl;
    this->help_print();
    cout<<endl;
}
void Knight::deading(){cout<<"Knight is dead"<<endl;}
Knight::~Knight(){}

Archer::Archer() : Warrior(8.0){}

void Archer::strike(Warrior & target)
{
    target.set_hp(target.get_hp()-this->get_weapon().damage_);
    cout<<"Archer dealt "<< this->get_weapon().damage_ <<" damage with "<< this->get_weapon().name_ <<endl;
    if (target.is_dead()) 
        target.deading();
}
void Archer::state()
{
    cout<<"State of Archer :";
    this->help_print();
    cout<<endl;
}
void Archer::deading(){cout<<"Archer is dead"<<endl;}
Archer::~Archer(){}

Mage::Mage(Spell* spell) : Warrior(5.0), spell_(spell){}
void Mage::strike(Warrior & target)
{
    target.set_hp(target.get_hp()-spell_->getDamage());
    cout<<"Mage dealt "<< spell_->getDamage() <<" damage with "<< this->get_weapon().name_<<endl;  
    spell_->magic_noise();
    if (target.is_dead()) 
        target.deading();
}

Mage::Mage() : Warrior(5.0){}

void Mage::state()
{
    cout<<"State of Mage :";
    this->help_print();
    cout<<endl;
}
void Mage::set_spell(Spell* spell)
{
    spell_=spell;
}
void Mage::deading(){cout<<"Mage is dead"<<endl;}
Mage::~Mage(){}

Spell::~Spell(){}
double fireball::getDamage(){return 20000;}
void fireball::magic_noise(){cout<<"CASTING FIREBALL"<<endl;};

double snowball::getDamage(){return 1;}
void snowball::magic_noise(){cout<<"CASTING SNOWBALL"<<endl;};

Factory::~Factory(){}
KnightFactory::~KnightFactory(){}
ArcherFactory::~ArcherFactory(){}
MageFactory::~MageFactory(){}