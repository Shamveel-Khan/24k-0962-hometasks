#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[20];
    int size;
    MinHeap() { size = 0; }

    void insert(int data) {
        size++;
        int index = size;
        arr[index] = data;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else break;
        }
    }

    void removeMin() {
        if (size == 0) return;
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (true) {
            int left = index * 2;
            int right = index * 2 + 1;
            int smallest = index;

            if (left <= size && arr[left] < arr[smallest]) smallest = left;
            if (right <= size && arr[right] < arr[smallest]) smallest = right;

            if (smallest != index) {
                swap(arr[index], arr[smallest]);
                index = smallest;
            } else break;
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap mh;
    
    mh.insert(100);
    mh.insert(50);
    mh.insert(75);
    mh.insert(60);
    mh.display();
    mh.insert(55);
    mh.display();
    mh.removeMin();
    mh.display();

    return 0;
}
