#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Warrior.h"

void say_hello();

int main()
{
    say_hello();
    return 0;
}

void say_hello()
{
    KnightFactory* knight_factory = new KnightFactory;
    ArcherFactory*  archer_factory  = new ArcherFactory;
    MageFactory*  mage_factory  = new MageFactory;
    Spell* fire_spell = new fireball;
    Spell* snow_spell = new snowball;
    Weapon Sword(1,1,"sword");
    Weapon Bow(2,10,"bow");
    Weapon Stuf(5,5,"stuff");

    vector<Warrior*> vec;
    vec.push_back( knight_factory->createWarrior());
    vec.push_back( archer_factory->createWarrior());
    vec.push_back( mage_factory->createWarrior(fire_spell));
    vec[0]->set_weapon(Sword);
    vec[1]->set_weapon(Bow);
    vec[2]->set_weapon(Stuf);
    cout<<"This is program about how fantasy guys beating each other."<<endl;
    cout<<"So let's have to example knight with sword, archer with bow and mage with stuf and spells"<<endl<<endl;

    for (auto elem : vec)
        elem->state();
    cout<<"Now knight will attack mage !"<<endl;
    vec[0]->strike(*vec[2]);
    cout<<endl;
    cout<<"Now mage will attack knight !"<<endl;
    vec[2]->strike(*vec[0]);
    cout<<"Poor poor knight"<<endl;
    cout<<"Maybe we should nerf some magic spells. Let give mage another spell !"<<endl;
    static_cast<Mage*> (vec[2])->set_spell(snow_spell);
    vec[2]->strike(*vec[1]);
    cout<<"Let's look on archer :"<<endl;
    cout<<"hp = " << vec[1]->get_hp() << endl;
    cout<<"Much better"<<endl;
    vec[1]->strike(*vec[2]);
    vec[1]->strike(*vec[2]);
    vec[1]->strike(*vec[2]);
    vec[1]->strike(*vec[2]);
    cout<<"Well, Archer attacking the corps now"<<endl<<endl;
    cout<<"That's all, goodbye!"<<endl;
    for (Warrior * elem: vec)
    {
        delete elem;
    }

    delete knight_factory;
    delete archer_factory;
    delete mage_factory;
    delete fire_spell;
    delete snow_spell;

}