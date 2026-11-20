
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(T value) {
        elements.push_back(value);
        cout << value << " pushed into stack." << endl;
    }

    void pop() {
        if (empty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }

        cout << elements.back() << " popped from stack." << endl;
        elements.pop_back();
    }

    void top() const {
        if (empty()) {
            cout << "Stack is empty! No top element." << endl;
            return;
        }

        cout << "Top element: " << elements.back() << endl;
    }

    bool empty() const {
        return elements.empty();
    }
    void display() const {
        if (empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (auto it = elements.rbegin();
             it != elements.rend(); ++it) {
            cout << *it << " ";
        }

        cout << endl;
    }
};

int main() {

    cout << "\n===== INTEGER STACK =====" << endl;

    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();
    intStack.top();
    intStack.pop();
    intStack.display();

    cout << "\n===== FLOAT STACK =====" << endl;

    Stack<float> floatStack;

    floatStack.push(10.5f);
    floatStack.push(20.5f);
    floatStack.push(30.5f);

    floatStack.display();
    floatStack.top();
    floatStack.pop();
    floatStack.display();
    cout << "\n===== STRING STACK =====" << endl;

    Stack<string> stringStack;

    stringStack.push("Apple");
    stringStack.push("Banana");
    stringStack.push("Orange");

    stringStack.display();
    stringStack.top();
    stringStack.pop();
    stringStack.display();

    cout << "\n===== EMPTY STACK TEST =====" << endl;

    Stack<int> emptyStack;

    emptyStack.pop();
    emptyStack.top();

    return 0;
}
