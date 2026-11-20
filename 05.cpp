
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Student : public Person {
protected:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c)
        : Person(n, a) {
        studentID = id;
        course = c;
        }
    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};


class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisor;

public:
        GraduateStudent(string n, int a, int id, string c,
                    string topic, string sup)
        : Student(n, a, id, c) {
        researchTopic = topic;
        supervisor = sup;
    }

   
    void displayGraduate() {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
};


int main() {

    
    cout << "========== STUDENT DETAILS ==========" << endl;

    Student s1("Rahul", 20, 101, "Computer Science");
    s1.displayStudent();

  
    cout << "\n===== GRADUATE STUDENT DETAILS =====" << endl;

    GraduateStudent g1(
        "Priya",
        24,
        201,
        "Information Technology",
        "Artificial Intelligence",
        "Dr. Sharma"
    );

    g1.displayGraduate();

    return 0;
}
