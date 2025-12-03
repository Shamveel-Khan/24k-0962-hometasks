#include <iostream>
using namespace std;

class Heap {
public:
    int arr[20];
    int size;
    Heap() { size = 0; }

    void insert(int data) {
        size++;
        int index = size;
        arr[index] = data;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else break;
        }
    }

    void removeMax() {
        if (size == 0) return;
        arr[1] = arr[size];
        size--;

        int index = 1;
        while (true) {
            int left = index * 2;
            int right = index * 2 + 1;
            int largest = index;

            if (left <= size && arr[left] > arr[largest]) largest = left;
            if (right <= size && arr[right] > arr[largest]) largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else break;
        }
    }

    void display() {
        for (int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap h;

    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.display();

    h.removeMax();
    h.display();

    h.insert(6);
    h.display();

    return 0;
}
