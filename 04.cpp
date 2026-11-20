
#include <iostream>
#include <memory>
using namespace std;


class Student {
private:
    string name;

public:
    Student(string n) {
        name = n;
        cout << "Student " << name << " created." << endl;
    }

    void display() const {
        cout << "Student Name: " << name << endl;
    }

    ~Student() {
        cout << "Student " << name << " destroyed." << endl;
    }
};

int main() {

    cout << "===== UNIQUE POINTER DEMO =====" << endl;
    unique_ptr<Student> ptr1 =
        make_unique<Student>("Rahul");

    ptr1->display();
    unique_ptr<Student> ptr2 = move(ptr1);

    cout << "Ownership transferred to ptr2." << endl;

    if (ptr1 == nullptr) {
        cout << "ptr1 is now empty." << endl;
    }

    ptr2->display();

    cout << "\n===== SHARED POINTER DEMO =====" << endl;
    shared_ptr<Student> shared1 =
        make_shared<Student>("Priya");

    cout << "Reference count: "
         << shared1.use_count() << endl;

    {
        shared_ptr<Student> shared2 = shared1;

        cout << "After sharing ownership:" << endl;

        cout << "Reference count: "
             << shared1.use_count() << endl;

        shared2->display();
    }

    cout << "After shared2 goes out of scope:" << endl;

    cout << "Reference count: "
         << shared1.use_count() << endl;

    cout << "\n===== REPEATED ALLOCATION DEMO =====" << endl;

    for (int i = 1; i <= 5; i++) {
        unique_ptr<Student> temp =
            make_unique<Student>("Student " + to_string(i));

        temp->display();
    }

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
