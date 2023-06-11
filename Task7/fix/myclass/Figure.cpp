#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
#include"Figure.h"

void tell_me()
{
    cout<<"This program is about geometry figures"<<endl;
    cout<<"I have circle, ellipse, square, rectangle, triangle"<<endl;
    cout<<"Let's create theme and look what they will say !"<<endl<<endl;
    vector<Figure*> arr;
    Point A,B,C,K;
    vector<Point> D;
    A.x_=0;
    A.y_=0;
    B.x_=0;
    B.y_=1;
    C.x_=1;
    C.y_=0;
    K.x_=1;
    K.y_=1;
    D={A,B};
    Circle cir(D);
    D={A,B,C};
    Triangle tri(D);
    Ellipse ell(D);
    D={A,B,K,C};    //левый нижний, левый верхний, правый верхний, правый нижний по часовой стрелке
    Square squ(D);
    C.x_=2;
    K.x_=2;
    D={A,B,K,C};
    Rectangle rec(D);
    arr.push_back(&tri);
    arr.push_back(&cir);
    arr.push_back(&ell);
    arr.push_back(&squ);
    arr.push_back(&rec);

    for(auto i:arr)
        cout<<*i;
}

double dist(const Point rhs, const Point lhs)
{
    return sqrt((rhs.x_-lhs.x_)*(rhs.x_-lhs.x_)+(rhs.y_-lhs.y_)*(rhs.y_-lhs.y_));
}

string help_print(Figure & A)
{
    string points="Point are : " + A.str_points();
    string perimetr="Perimetr is " +to_string(A.give_perimetr());
    string area="Area is " + to_string(A.give_area());
    return (points+"\n"+perimetr+"\n"+area+"\n");
}

void speach(Figure * an1)
{
    cout<<an1->give_perimetr()<<endl;
}


Figure::Figure()
{
    Point no_point ;
    no_point.x_=0;
    no_point.y_=0;
    points_={no_point};
}
Figure::Figure(vector<Point> vec): points_(vec){}

vector<Point> Figure::get_p(){return points_;}
string Figure::str_points()
{
    string about_points="";
    string point="";
    for(auto i:points_)
    {
        point=" ("+to_string(i.x_)+":"+to_string(i.y_)+")"+" ";
        about_points+=point;
    }
    return about_points;
}
string Figure::print(){return "0";}
Figure::~Figure(){}

std::ostream& operator<<(std::ostream& os, Figure & fig)
{
    os<<fig.print()<<endl;
    return os;
}

Circle::Circle():Figure(){}
Circle::Circle(vector<Point> vec):Figure(vec){}
double Circle::give_perimetr() 
{
    vector<Point> A;
    A=this->get_p();
    Point center=A[0];
    Point on=A[1];
    double radius=dist(center,on);
    return(2*radius*3.14);
}

double Circle::give_area()
{
    vector<Point> A;
    A=this->get_p();
    Point center=A[0];
    Point on=A[1];
    double radius=dist(center,on);
    return(3.14*radius*radius);
}

string Circle::print()
{
    return ((string)"Hello, i am Circle"+"\n"+help_print(*this));
}

Circle::~Circle(){}

Ellipse::Ellipse():Circle() {}
Ellipse::Ellipse(vector<Point> vec):Circle(vec) {}
double Ellipse::give_perimetr()
{
    //Беру эллиптический интеграл
    cout<<"I can't calcualte perimetr of ellipse"<<endl;
    return -1;
}

double Ellipse::give_area ()
{
    vector<Point> A;
    A=this->get_p();
    Point center=A[0];
    Point onx=A[1];
    Point ony=A[2];
    double a=dist(center,onx);
    double b=dist(center,ony);
    return(3.14*a*b);
}
string Ellipse::print () 
{
    return ((string)"Hello, i am Ellipse"+"\n"+help_print(*this));
}
Ellipse::~Ellipse(){}

Polygon::Polygon():Figure() {}
Polygon::Polygon(vector<Point> vec):Figure(vec) {}
double Polygon::give_perimetr(){return -1;}
double Polygon::give_area(){return -1;}
string Polygon::print(){return "0";}
Polygon::~Polygon(){}

Triangle::Triangle():Polygon(){};
Triangle::Triangle(vector<Point> vec):Polygon(vec){}
double Triangle::give_perimetr()
{
    vector<Point> A;
    A=this->get_p();
    Point B=A[0];
    Point C=A[1];
    Point D=A[2];   
    return(dist(B,C)+dist(C,D)+dist(D,B));
}
double Triangle::give_area ()
{
    vector<Point> A;
    A=this->get_p();
    Point B=A[0];
    Point C=A[1];
    Point D=A[2];
    double p=(this->give_perimetr())/2;
    double S=sqrt(p*(p-dist(B,C))*(p-dist(C,D))*(p-dist(D,B)));
    return S;
}
string Triangle::print ()
{
    return ((string)"Hello, i am Triangle"+"\n"+help_print(*this));
}
Triangle::~Triangle(){};


Square::Square():Polygon(){}
Square::Square(vector<Point> vec):Polygon(vec){}
double Square::give_perimetr()//left bottom and right top
{
    vector<Point> A;
    A=this->get_p();
    Point lt=A[0];
    Point rt=A[1];
    return 4*dist(lt,rt);
}
double Square::give_area ()
{
    vector<Point> A;
    A=this->get_p();
    Point lt=A[0];
    Point rt=A[1];
    return dist(lt,rt)*dist(lt,rt);
}
string Square::print () 
{
    return ((string)"Hello, i am Square"+"\n"+help_print(*this));
}
Square::~Square(){}

Rectangle::Rectangle() : Square(){};
Rectangle::Rectangle(vector<Point> vec) : Square(vec){};

double Rectangle::give_perimetr()
{
    vector<Point> A;
    A=this->get_p();
    Point lb=A[0];
    Point lt=A[1];
    Point rt=A[2];
    Point rb=A[3];
    // return(2*(rt.x_-lb.x_)+2*(rt.y_-lb.y_));
    return(2*dist(lt,rt)+2*dist(lb,rb));
}
double Rectangle::give_area ()
{
    vector<Point> A;
    A=this->get_p();
    Point lb=A[0];
    Point lt=A[1];
    Point rt=A[2];
    Point rb=A[3];
    // return(2*(rt.x_-lb.x_)+2*(rt.y_-lb.y_));
    return(dist(lt,rt)*dist(lb,rb));
}
string Rectangle::print ()
{
    return ((string)"Hello, i am Rectangle"+"\n"+help_print(*this)); 
}
Rectangle::~Rectangle(){}