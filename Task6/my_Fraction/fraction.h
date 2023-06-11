class Fraction
{
private:
    int _up;
    unsigned int _down;
public:
    Fraction();
    Fraction(int, unsigned int);
    ~Fraction();
    int get_up();
    unsigned int get_down();
    void set_up(int);
    void set_down(unsigned int);
    void change_down(int);    
    void cut();
    friend std::ostream& operator<<(std::ostream&, const Fraction);
    friend std::istream& operator>>(std::istream&, Fraction&);

	friend Fraction operator+(Fraction, Fraction);
	friend Fraction operator-(Fraction, Fraction);
	friend Fraction operator*(Fraction, Fraction);
	friend Fraction operator/(Fraction, Fraction);

    friend bool operator == (Fraction, Fraction);
    friend bool operator != (Fraction, Fraction);
    friend bool operator <  (Fraction, Fraction);
    friend bool operator >  (Fraction, Fraction);

    Fraction operator+=(Fraction&);
    Fraction operator-=(Fraction&);
    Fraction operator*=(Fraction&);
    Fraction operator/=(Fraction&);

    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    operator double();
};
