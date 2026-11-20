
#include <iostream>
using namespace std;


class Calculator {
public:

    
    int add(int a, int b) {
        return a + b;
    }

    
    double add(double a, double b) {
        return a + b;
    }

   
    int add(int a, int b, int c) {
        return a + b + c;
    }
};


class ComplexNumber {
private:
    double real;
    double imag;

public:

   
    ComplexNumber(double r, double i) {
        real = r;
        imag = i;
    }

    
    ComplexNumber operator+(const ComplexNumber& obj) {
        return ComplexNumber(
            real + obj.real,
            imag + obj.imag
        );
    }

    
    void display() {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};


int main() {

    
    Calculator calc;

    cout << "===== FUNCTION OVERLOADING =====" << endl;

    cout << "Addition of two integers: "
         << calc.add(10, 20) << endl;

    cout << "Addition of two doubles: "
         << calc.add(10.5, 20.5) << endl;

    cout << "Addition of three integers: "
         << calc.add(10, 20, 30) << endl;

    
    cout << "\n===== OPERATOR OVERLOADING =====" << endl;

    ComplexNumber c1(3, 4);
    ComplexNumber c2(2, 5);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    
    ComplexNumber c3 = c1 + c2;

    cout << "Result after addition: ";
    c3.display();

    return 0;
}
