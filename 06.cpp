
#include <iostream>
using namespace std;


class Shape {
public:

    
    virtual double area() = 0;

    
    virtual ~Shape() {
    }
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    
    double area() override {
        return 3.14159 * radius * radius;
    }
};


class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    
    double area() override {
        return length * width;
    }
};


class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    
    double area() override {
        return 0.5 * base * height;
    }
};


int main() {

    
    Circle c(5);
    Rectangle r(10, 4);
    Triangle t(6, 8);

    
    Shape* shape1 = &c;
    Shape* shape2 = &r;
    Shape* shape3 = &t;

    cout << "===== AREA CALCULATIONS =====" << endl;

   
    cout << "Area of Circle: "
         << shape1->area() << endl;

    cout << "Area of Rectangle: "
         << shape2->area() << endl;

    cout << "Area of Triangle: "
         << shape3->area() << endl;

    return 0;
}
