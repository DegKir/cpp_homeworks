#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Lesson;
struct Student;

struct Student
{
    Student() : name("NO_NAME"){};
    string name;
    vector<Lesson *> visited_lessons;
};

struct Lesson
{
    strin   g name;
    vector<Student *> list_of_present;
    vector<bool> attended;

    Lesson() : name("Lesson"), attended(vector<bool>(0)){};
    Lesson(string _name, vector<bool> _attended, vector<Student> &students, vector<Lesson> &lessons) : name(_name), attended(_attended), list_of_present(){
                                                                                                                                             // for(size_t i = 0; i < attended.size();++i)
                                                                                                                                             // {
                                                                                                                                             //     if(attended[i])
                                                                                                                                             //         {
                                                                                                                                             //             list_of_present.push_back(&students[i]);
                                                                                                                                             //             students[i].visited_lessons.push_back(this);
                                                                                                                                             //         }
                                                                                                                                             // }
                                                                                                                                         };
};

void init_students(vector<Student> &);
void init_lessons(vector<Student> &students, vector<Lesson> &lessons);
void init_connection(vector<Student> &, vector<Lesson> &);
void list_of_students(Lesson &);
void list_of_lessons(Student &);
void say_hello(vector<Student> &, vector<Lesson> &);
void new_lesson(vector<Student> &, vector<Lesson> &, vector<bool>, string);
void tell_me_about_lesson(Lesson);

int main()
{
    bool menu_param = true;
    vector<Lesson> lessons;
    vector<Student> students;
    init_students(students);
    init_lessons(students, lessons);
    init_connection(students, lessons);
    say_hello(students, lessons);
    while (menu_param)
    {
        cout << "Do you want to add a lection ?" << endl
             << "1.Yes" << endl
             << "0.No" << endl;
        cin >> menu_param;
        if (menu_param)
        {
            bool he_was;
            vector<bool> attended;
            string name;
            cout << "What its name ?";
            cin >> name;
            cout << "If this student was on lection, give me 1" << endl
                 << "if he wasn't, give me 0  " << endl;
            for (auto &elem : students)
            {
                cout << elem.name << " ";
                cin >> he_was;
                cout << endl;
                attended.push_back(he_was);
            }
            new_lesson(students, lessons, attended, name);
        }
        else
        {
            continue;
        }
        list_of_students(lessons[lessons.size() - 1]);
    }
    cout << "Goodbye!";
    return 0;
}

void init_students(vector<Student> &students)
{
    Student A, B, C, D;
    A.name = "Kars";
    B.name = "Joseph";
    C.name = "Cesar";
    D.name = "Vaamu";
    students.push_back(A);
    students.push_back(B);
    students.push_back(C);
    students.push_back(D);
}

void init_lessons(vector<Student> &students, vector<Lesson> &lessons)
{
    Lesson algebra("algebra", {true, true, true, true}, students, lessons),
        physics("physics", {true, true, false, false}, students, lessons),
        geometry("geometry", {true, false, true, false}, students, lessons);
    lessons.push_back(algebra);
    lessons.push_back(physics);
    lessons.push_back(geometry);
}

void init_connection(vector<Student> &students, vector<Lesson> &lessons)
{
    for (auto &lesson : lessons)
    {
        vector<bool> attended = lesson.attended;
        for (size_t i = 0; i < attended.size(); ++i)
        {
            if (attended[i])
            {
                lesson.list_of_present.push_back(&students[i]);
                students[i].visited_lessons.push_back(&lesson);
            }
        }
    }
}

void list_of_students(Lesson &lesson)
{
    cout << "These students attended " << lesson.name << " : ";
    for (unsigned i = 0; i < lesson.list_of_present.size(); ++i)
        cout << (lesson.list_of_present[i]->name) << ", ";
    cout << endl;
}
void list_of_lessons(Student &studient)
{
    cout << studient.name << " attended lessons ";
    for (unsigned i = 0; i < studient.visited_lessons.size(); ++i)
        cout << (studient.visited_lessons[i]->name) << ", ";
    cout << endl;
}

void say_hello(vector<Student> &students, vector<Lesson> &lessons)
{
    cout << "Welcome to our school" << endl;
    cout << "Let me say to you who attended lessons today:" << endl;

    for (auto lesson : lessons)
        list_of_students(lesson);
    cout << endl;

    cout << "Let me say what lections each students attended today:" << endl;
    for (auto student : students)
        list_of_lessons(student);
    cout << endl;
}

void new_lesson(vector<Student> &students, vector<Lesson> &lessons, vector<bool> attended, string name)
{
    Lesson lesson(name, attended, students, lessons);
    for (size_t i = 0; i < attended.size(); ++i)
    {
        if (attended[i])
        {
            lesson.list_of_present.push_back(&students[i]);
            students[i].visited_lessons.push_back(&lesson);
        }
    }
    lessons.push_back(lesson);
}