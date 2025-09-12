#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray() {
        data = nullptr;
        size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        int* newData = new int[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        size++;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.print();
    arr.push_back(4);
    arr.print();
    return 0;
}