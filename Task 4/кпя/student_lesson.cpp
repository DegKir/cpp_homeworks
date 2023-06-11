#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Lesson;
struct Student;

/*Принимает указатель на структуру студента
Пишет в консоль какие уроки он посетил*/
void list_of_lessons(Student*);
/*Принимает указатель на структуру лекции
Пишет в консоль кто посетил данную лекцию*/
void list_of_students(Lesson*);

/*
Принимает вектор логических значений, 
вектор указателей на структуру студент
и указатель на Lesson
Lesson после этого имеет список студентов
*/
void muster (vector<Student*>, Lesson* );

// void new_lesson(vector<Lesson*>, Lesson* );

struct Student
{
    string name;
    vector<Lesson*> visited_lessons;
};

struct Lesson
{
    Lesson():name("Lesson"),attended(vector<bool> (0))
    {
    };

    Lesson(string _name, vector<bool> _attended):
        name(_name), attended(_attended)
    {  
    };
    string name;
    vector<Student*> list_of_present;
    vector<bool> attended;
};

int main()
{
    bool menu_param=false;
    bool he_was=false;
    vector<vector<bool>> attended
    {
        {true,true,true,true},
        {true,true,false,false},
        {true,false,false,true},
    };
    vector<Student*> students;
    vector<Lesson*> lessons;
    vector<Lesson> lessons_itself;
    Student A,B,C,D;
    Lesson algebra, physics, geometry;
    A.name = "Kars";
    B.name = "Joseph";
    C.name = "Cesar";
    D.name = "Vaamu";
    students.push_back(&A);
    students.push_back(&B);
    students.push_back(&C);
    students.push_back(&D);

    algebra.name = "algebra";
    algebra.attended={true,true,true,true};
    lessons_itself.push_back(algebra);
    physics.name = "physics";
    physics.attended={true,true,false,false};
    lessons_itself.push_back(physics);
    geometry.name = "geometry";    
    geometry.attended={true,false,true,false};
    lessons_itself.push_back(geometry);
    lessons.push_back(&algebra);
    lessons.push_back(&physics);
    lessons.push_back(&geometry);

    cout<<"Welcome to our school"<<endl;
    cout<<"Let me say to you who attended lessons today:"<<endl;

    for(unsigned i=0;i<lessons.size();++i)
    {
        muster(students,lessons[i]);
        list_of_students(lessons[i]);
    }

    cout<<endl;
    cout<<"Let me say what lections each students attended today:"<<endl;
    
    for(unsigned i=0;i<students.size();++i)
        list_of_lessons(students[i]);



    cout<<endl<<"Do you want to add new lesson ?"<<endl<<"1.Yes"<<endl<<"2.No"<<endl;
    cin >> menu_param;

    if(menu_param)
    {
        vector<bool> attended_raw;
        string name;
        cout<<"Please,give me name of new lesson"<<endl;
        cin>>name;
        cout<<"If this student was on lection, give me 1"<<endl<<
            "if he wasn't, give me 0  "<<endl;
        for (auto &elem:students)
        {
            cout<<elem->name<<" ";
            cin>>he_was;
            cout<<endl;
            attended_raw.push_back(he_was);
        }
        Lesson NEW_LESSON(name,attended_raw);

        muster(students,&NEW_LESSON);
        Les.push_back(NEW_LESSON);
    }

    list_of_students(lessons[3]);

    return 0;
}

void muster(vector<Student*> students,  Lesson* lesson)
{
    vector<bool> attended = lesson->attended;
    for(unsigned i = 0; i < attended.size();++i)
         if(attended[i])
        {
            lesson->list_of_present.push_back(students[i]);
            students[i]->visited_lessons.push_back(lesson);
        }
}

void list_of_students(Lesson* lesson)
{
    cout<<"These students attended "<<lesson->name<< " : ";
    for (unsigned i=0;i < lesson->list_of_present.size();++i)
        cout<< (lesson->list_of_present[i]->name)<<", ";
    cout<<endl;

}

void list_of_lessons(Student* stud)
{
    cout<<stud->name<< " attended lessons ";
    for (unsigned i=0;i < stud->visited_lessons.size();++i)
        cout<< (stud->visited_lessons[i]->name)<<", ";
    cout<<endl;
}
