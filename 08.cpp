
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;

    virtual ~Shape() {
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }
};


class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Triangle." << endl;
    }
};


class ShapeFactory {
public:

    
    static unique_ptr<Shape> createShape(string type) {

        if (type == "circle") {
            return make_unique<Circle>();
        }
        else if (type == "rectangle") {
            return make_unique<Rectangle>();
        }
        else if (type == "triangle") {
            return make_unique<Triangle>();
        }
        else {
            cout << "Invalid shape type!" << endl;
            return nullptr;
        }
    }
};


int main() {

    cout << "===== FACTORY DESIGN PATTERN =====" << endl;

    
    cout << "\nCreating Circle:" << endl;
    unique_ptr<Shape> shape1 =
        ShapeFactory::createShape("circle");

    if (shape1) {
        shape1->draw();
    }

   
    cout << "\nCreating Rectangle:" << endl;
    unique_ptr<Shape> shape2 =
        ShapeFactory::createShape("rectangle");

    if (shape2) {
        shape2->draw();
    }

    
    cout << "\nCreating Triangle:" << endl;
    unique_ptr<Shape> shape3 =
        ShapeFactory::createShape("triangle");

    if (shape3) {
        shape3->draw();
    }

    
    cout << "\nCreating Unknown Shape:" << endl;
    unique_ptr<Shape> shape4 =
        ShapeFactory::createShape("square");

    return 0;
}
