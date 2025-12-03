#include <iostream>
using namespace std;

class Hash {
private:
    int arr[100];
    int size;

public:
    Hash() { size = 0; }

    void insert(int x) {
        int i = size - 1;
        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x;
        size++;
    }

    void removeValue(int x) {
        int index = -1;
        for (int i = 0; i < size; i++)
            if (arr[i] == x) index = i;

        if (index == -1) return;

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void search(int x) {
        for (int i = 0; i < size; i++)
            if (arr[i] == x) {
                cout << x << " found\n";
                return;
            }
        cout << x << " not found\n";
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Hash h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);

    h.display();

    cout << "Remove 4\n";
    h.removeValue(4);

    h.display();

    h.search(5);
    h.search(6);

    return 0;
}