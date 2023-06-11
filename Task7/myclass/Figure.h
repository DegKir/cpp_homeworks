struct Point
{
    int x_;
    int y_;
};

class Figure
{
private:
    vector<Point> points_;
    friend std::ostream& operator<<(std::ostream&, Figure & );
public:
    Figure();
    vector<Point> get_p();
    Figure(vector<Point>);
    virtual double give_perimetr ()  =0;
    virtual double give_area ()  =0;
    virtual string print ();
    string str_points();
    virtual ~Figure();
};

class Circle: public Figure
{
public:
    Circle();
    Circle(vector<Point>);
    virtual double give_perimetr() override;
    virtual double give_area () override;
    virtual string print () override;
    virtual ~Circle();
};

class Ellipse: public Circle
{
public:
    Ellipse();
    Ellipse(vector<Point>);
    virtual double give_perimetr() override;
    virtual double give_area () override;
    virtual string print () override;
    virtual ~Ellipse();
};
class Polygon: public Figure
{
public:
    Polygon();
    Polygon(vector<Point>);
    virtual double give_perimetr() =0;
    virtual double give_area () =0;
    virtual string print () =0;
    virtual ~Polygon();
};
class Triangle: public Polygon
{
public:
    Triangle();
    Triangle(vector<Point>);
    virtual double give_perimetr()  override;
    virtual double give_area ()  override;
    virtual string print () override;
    virtual ~Triangle();
};
class Square: public Polygon
{
public:
    Square();
    Square(vector<Point>);
    virtual double give_perimetr()  override;
    virtual double give_area ()  override;
    virtual string print () override;
    virtual ~Square();
};
class Rectangle: public Square
{
public:
    Rectangle();
    Rectangle(vector<Point>);
    virtual double give_perimetr()  override;
    virtual double give_area ()  override;
    virtual string print () override;
    virtual ~Rectangle();
};


string help_print(Figure &);
void tell_me();
double dist(const Point, const Point);
