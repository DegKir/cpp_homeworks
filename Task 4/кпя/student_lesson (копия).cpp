#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Lesson;
struct Student;

void list_of_lectures(Student*);
void list_of_students(Lesson*);

/*
Принимает вектор логических значений, 
вектор указателей на структуру студент
и указатель на Lesson
Lesson после этого имеет список студентов
*/
void muster (vector<bool>, vector<Student*>, Lesson* );
// void new_student(vector<bool>, vector<Lesson*> , Student*); Не написано
struct Student
{
    string name;
    int number;
    vector<Lesson*> visited_lessons;
};

struct Lesson
{
    string name;
    int number;
    vector<Student*> list_of_present;
};


int main()
{
    vector<vector<bool>> attended
    {
        {true,true,true},
        {true,true,false},
        {true,false,false}
    };

    Student A,B,C;
    Lesson algebra, physics, geometry;
    vector<Student*> students;
    vector<Lesson*> lessons;
    A.name = "Kars";
    A.number = 0;
    B.name = "Joseph";
    B.number = 1;
    C.name = "Cesar";
    C.number = 2;
    
    students.push_back(&A);
    students.push_back(&B);
    students.push_back(&C);

    lessons.push_back(&algebra);
    algebra.name = "algebra";
    algebra.number = 0;

    lessons.push_back(&physics);
    physics.name = "physics";
    physics.number = 1;

    lessons.push_back(&geometry);
    geometry.name = "geometry";
    geometry.number = 2;

    for(auto i=0;i<lessons.size();++i)
    {
        muster(attended[i],students,lessons[i]);
        list_of_students(lessons[i]);
    }


    return 0;
}

void muster(vector<bool> stud_was,vector<Student*> studients,  Lesson* lesson)
{
    for(int i = 0; i < stud_was.size();++i)
        if(stud_was[i])
        {
            lesson->list_of_present.push_back(studients[i]);
            studients[i]->visited_lessons.push_back(lesson);
        }
}

void list_of_students(Lesson* lesson)
{
    cout<<"These students attended "<<lesson->name<< " : ";
    for (int i=0;i < lesson->list_of_present.size();++i)
        cout<< (lesson->list_of_present[i]->name)<<", ";
    cout<<endl;

}

void list_of_lectures(Student* stud)
{
    // Lesson* les = stud->visited_lessons[0];
    // cout<< les->number_of_lesson;
    cout<<stud->name<< " attended lessons ";
    for (int i=0;i < stud->visited_lessons.size();++i)
        cout<< (stud->visited_lessons[i]->name)<<", ";
    cout<<endl;
}

void init_students(vector<Student*>& students)
{
    Student A,B,C;
    A.name = "Kars";
    A.number = 0;
    B.name = "Joseph";
    B.number = 1;
    C.name = "Cesar";
    C.number = 2;
    students.push_back(&A);
    students.push_back(&B);
    students.push_back(&C);
}
