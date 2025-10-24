#include <iostream>
using namespace std;

struct Element {
    int value;
    Element* next;
    Element* prev;
    Element(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class DoublyList {
public:
    Element* start;
    DoublyList() : start(nullptr) {}
    
    void insert(int val) {
        Element* newElem = new Element(val);
        if (start == nullptr) {
            start = newElem;
            return;
        }
        Element* walker = start;
        while (walker->next) {
            walker = walker->next;
        }
        walker->next = newElem;
        newElem->prev = walker;
    }
    
    void display() {
        Element* walker = start;
        while (walker) {
            cout << walker->value << " ";
            walker = walker->next;
        }
        cout << endl;
    }
    
    void exchange(Element* first, Element* second) {
        int temp = first->value;
        first->value = second->value;
        second->value = temp;
    }

    Element* divide(Element* left, Element* right) {
        int pivotVal = right->value;
        Element* marker = left->prev;
        for (Element* current = left; current != right; current = current->next) {
            if (current->value <= pivotVal) {
                marker = (marker == nullptr) ? left : marker->next;
                exchange(marker, current);
            }
        }
        marker = (marker == nullptr) ? left : marker->next;
        exchange(marker, right);
        return marker;
    }
    
    void sortQuick(Element* left, Element* right) {
        if (left && right && left != right && left != right->next) {
            Element* pivotNode = divide(left, right);
            sortQuick(left, pivotNode->prev);
            sortQuick(pivotNode->next, right);
        }
    }

    void sortQuick() {
        sortQuick(start, getLast());
    }

    Element* getLast() {
        Element* walker = start;
        while (walker && walker->next) {
            walker = walker->next;
        }
        return walker;
    }
};

int main() {
    DoublyList numbers;
    numbers.insert(10);
    numbers.insert(7);
    numbers.insert(8);
    numbers.insert(9);
    numbers.insert(1);
    numbers.insert(5);
    numbers.insert(3);

    cout << "Original list: ";
    numbers.display();

    numbers.sortQuick();

    cout << "Sorted list using quicksort: ";
    numbers.display();

    return 0;
}
