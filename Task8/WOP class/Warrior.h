struct Weapon
{
    Weapon();
    Weapon(double,double,std::string);
    double damage_;
    double range_;
    std::string name_;
};

class Spell;
class Warrior
{
private:
    int hp_;
    Weapon right_hand;
public:
    virtual void strike(Warrior & ) = 0;
    virtual void state() = 0;
    Weapon get_weapon();
    void set_weapon(Weapon);
    Warrior();
    Warrior(double);
    double get_hp ();
    void set_hp(double);
    void help_print();
    bool is_dead();
    virtual void deading();
    virtual ~Warrior();
};

class Knight : public Warrior
{
public:
    virtual void strike(Warrior & target) override;
    virtual void state() override;
    virtual void deading() override;
    Knight();
    virtual ~Knight() ;
};

class Archer : public Warrior
{
private:
public:
    virtual void strike(Warrior & target) override;
    virtual void state() override;
    virtual void deading() override;
    Archer();
    virtual ~Archer() ;
};

class Mage : public Warrior
{
private:
    Spell* spell_;
public:
    virtual void strike(Warrior & target) override;
    virtual void state() override;
    virtual void deading() override;
    Mage(Spell*);
    Mage();
    void set_spell(Spell*);
    virtual ~Mage();
};

class Factory
{
public:
    virtual Warrior* createWarrior()=0 ;
    virtual ~Factory(); 
};      

class KnightFactory : public Factory
{
public:
    virtual Warrior* createWarrior() override;
    virtual ~KnightFactory(); 
};


class ArcherFactory : public Factory
{
public:
    virtual Warrior* createWarrior() override;
    virtual ~ArcherFactory(); 
};

class MageFactory : public Factory
{
public:
    virtual Warrior* createWarrior() override;
    virtual Warrior* createWarrior(Spell* Spell) ;
    virtual ~MageFactory(); 
};

class Spell
{
public: 
    virtual double getDamage() = 0;
    virtual void magic_noise() = 0;
    virtual ~Spell();
};

class fireball : public Spell
{
    virtual double getDamage() override;
    virtual void magic_noise() override;
};

class snowball : public Spell
{
    virtual double getDamage() override;
    virtual void magic_noise() override;
};