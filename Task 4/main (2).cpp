//CREATED BY ALYAEV ROMAN B04-906

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Answer
{
    student,
    lesson
};

void answer_the_question(Answer answer)
{
    switch(answer)
    {
        case 0:
            cout << "Write the surname: (There are Ivanov/Belov/Solntseva)" << endl;
            break;
        case 1:
            cout << "Write the title: (There are Math, Physics, English, History, PE-lesson)" << endl;
            break;
        default:
            cout << "Oops, there's a mistake!";
    }
}

struct Lesson;

struct Student;

struct Student
{
    string name_surname;
    vector<Lesson*> lessons_been;
};

struct Lesson
{
    string title;
    vector<Student*> students_been;
};

int main()
{
    string question;
    Lesson math, english, history, physics, p_education;
    Student student1, student2, student3;
    Student *pstudent1 = &student1;
    Student *pstudent2 = &student2;
    Student *pstudent3 = &student3;
    Lesson *plesson1 = &math;
    Lesson *plesson2 = &english;
    Lesson *plesson3 = &history;
    Lesson *plesson4 = &physics;
    Lesson *plesson5 = &p_education;
    student1.name_surname = "Ivanov Egor";
    student2.name_surname = "Belov Konstantin";
    student3.name_surname = "Solntseva Svetlana";
    math.title = "Math";
    english.title = "English";
    history.title = "History";
    physics.title = "Physics";
    p_education.title = "PE-lesson";
    student1.lessons_been.push_back(plesson4);
    student1.lessons_been.push_back(plesson5);
    student1.lessons_been.push_back(plesson2);
    student2.lessons_been.push_back(plesson1);
    student2.lessons_been.push_back(plesson3);
    student2.lessons_been.push_back(plesson2);
    student3.lessons_been.push_back(plesson1);
    student3.lessons_been.push_back(plesson4);
    student3.lessons_been.push_back(plesson5);
    math.students_been.push_back(pstudent2);
    math.students_been.push_back(pstudent3);
    english.students_been.push_back(pstudent1);
    english.students_been.push_back(pstudent2);
    history.students_been.push_back(pstudent2);
    physics.students_been.push_back(pstudent1);
    physics.students_been.push_back(pstudent3);
    p_education.students_been.push_back(pstudent1);
    p_education.students_been.push_back(pstudent3);
    cout << "What are you looking for? (student/lesson)" << endl;
    cin >> question;
    if (question == "student")
    {
        answer_the_question(student);
        string NS;
        cin >> NS;
        if (NS == "Ivanov")
        {
            cout << endl << "Student: " << student1.name_surname << endl;
            cout << "Student was at: " << endl;
            for (auto elem: student1.lessons_been)
            {
                cout << elem->title << endl;
            }
        }
        if (NS == "Belov")
        {
            cout << endl << "Student: " << student2.name_surname << endl;
            cout << "Student was at: " << endl;
            for (auto elem: student2.lessons_been)
            {
                cout << elem->title << endl;
            }
        }
        if (NS == "Solntseva")
        {
            cout << endl << "Student: " << student3.name_surname << endl;
            cout << "Student was at: " << endl;
            for (auto elem: student3.lessons_been)
            {
                cout << elem->title << endl;
            }
        }
    }
    if (question == "lesson")
    {
        answer_the_question(lesson);
        string T;
        cin >> T;
        if (T == "Math")
        {
            cout << "At this lesson were: " << endl;
            for (auto elem: math.students_been)
            {
                cout << elem->name_surname << endl;
            }
        }
        if (T == "Physics")
        {
            cout << "At this lesson were: " << endl;
            for (auto elem: physics.students_been)
            {
                cout << elem->name_surname << endl;
            }
        }
        if (T == "English")
        {
            cout << "At this lesson were: " << endl;
            for (auto elem: english.students_been)
            {
                cout << elem->name_surname << endl;
            }
        }
        if (T == "History")
        {
            cout << "At this lesson were: " << endl;
            for (auto elem: history.students_been)
            {
                cout << elem->name_surname << endl;
            }
        }
        if (T == "PE-lesson")
        {
            cout << "At this lesson were: " << endl;
            for (auto elem: p_education.students_been)
            {
                cout << elem->name_surname << endl;
            }
        }
    }
    cout << endl;
    return 0;
}

