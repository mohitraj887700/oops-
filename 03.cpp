
#include <iostream>
#include <utility>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray() {
        size = 0;
        arr = nullptr;
        cout << "Default Constructor Called" << endl;
    }

    DynamicArray(int s) {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = (i + 1) * 10;
        }

        cout << "Parameterized Constructor Called" << endl;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;

        if (size > 0) {
            arr = new int[size];

            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        } else {
            arr = nullptr;
        }

        cout << "Copy Constructor Called" << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            int* newArr = nullptr;

            if (other.size > 0) {
                newArr = new int[other.size];

                for (int i = 0; i < other.size; i++) {
                    newArr[i] = other.arr[i];
                }
            }

            delete[] arr;
            arr = newArr;
            size = other.size;
        }

        cout << "Copy Assignment Operator Called" << endl;
        return *this;
    }

    DynamicArray(DynamicArray&& other) noexcept {
        arr = other.arr;
        size = other.size;

        other.arr = nullptr;
        other.size = 0;

        cout << "Move Constructor Called" << endl;
    }
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] arr;

            arr = other.arr;
            size = other.size;

            other.arr = nullptr;
            other.size = 0;
        }

        cout << "Move Assignment Operator Called" << endl;
        return *this;
    }

  
    void display() const {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    
    ~DynamicArray() {
        delete[] arr;
        cout << "Destructor Called" << endl;
    }
};


int main() {

    cout << "\n--- Default Constructor ---" << endl;
    DynamicArray obj1;

    cout << "\n--- Parameterized Constructor ---" << endl;
    DynamicArray obj2(3);
    obj2.display();

    cout << "\n--- Copy Constructor ---" << endl;
    DynamicArray obj3(obj2);
    obj3.display();

    cout << "\n--- Copy Assignment ---" << endl;
    DynamicArray obj4;
    obj4 = obj2;
    obj4.display();

    cout << "\n--- Move Constructor ---" << endl;
    DynamicArray obj5(move(obj2));
    obj5.display();

    cout << "\n--- Move Assignment ---" << endl;
    DynamicArray obj6;
    obj6 = move(obj3);
    obj6.display();

    cout << "\n--- Final Arrays ---" << endl;
    cout << "Object 4: ";
    obj4.display();

    cout << "Object 5: ";
    obj5.display();

    cout << "Object 6: ";
    obj6.display();

    return 0;
}
