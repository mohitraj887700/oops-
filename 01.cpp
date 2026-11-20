
#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Data Types and Variables
    string name;
    int age;
    double marks1, marks2, total, average;
    char grade;

    // 2. Constant
    const int MAX_MARKS = 100;

    // 3. Input
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter marks in Subject 1: ";
    cin >> marks1;

    cout << "Enter marks in Subject 2: ";
    cin >> marks2;

    // 4. Arithmetic Operators
    total = marks1 + marks2;
    average = total / 2.0;

    // 5. Relational and Logical Operators
    bool validMarks = (marks1 >= 0 && marks1 <= MAX_MARKS) &&
                      (marks2 >= 0 && marks2 <= MAX_MARKS);

    bool eligible = (age >= 18 && average >= 40);

    // 6. Output
    cout << "\n========== STUDENT RESULT ==========\n";

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;

    if (!validMarks) {
        cout << "Invalid marks! Please enter marks between 0 and "
             << MAX_MARKS << "." << endl;
    }
    else {
        cout << "Subject 1 Marks: " << marks1 << endl;
        cout << "Subject 2 Marks: " << marks2 << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;

        // 7. Grade Calculation
        if (average >= 75)
            grade = 'A';
        else if (average >= 60)
            grade = 'B';
        else if (average >= 40)
            grade = 'C';
        else
            grade = 'F';

        cout << "Grade: " << grade << endl;

        cout << "Eligibility: "
             << (eligible ? "Eligible" : "Not Eligible")
             << endl;
    }

    cout << "====================================\n";

    return 0;
}
