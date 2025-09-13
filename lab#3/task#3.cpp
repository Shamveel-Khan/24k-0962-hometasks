#include <iostream>
using namespace std;

class nodeInt {
public:
    int data;
    nodeInt* next;
    nodeInt* prev;

    nodeInt(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class doublylist {
private:
    nodeInt* head;

public:
    doublylist() : head(nullptr) {} 
    ~doublylist() {
        nodeInt* current = head;
        while (current) {
            nodeInt* nextnodeInt = current->next;
            delete current;
            current = nextnodeInt;
        }
    }
    void addAtEnd(int value) {
        nodeInt* newNode = new nodeInt(value);
        if (!head) {
            head = newNode;
            return;
        }
        nodeInt* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    void print() {
        cout << "Doubly Linked List: ";
        nodeInt* current = head;
        while (current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout<<"null"<< endl;
    }

    bool search(int value) {
        nodeInt* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void deleteFromStart() {
        if (!head) return;
        nodeInt* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }
};

int main() {
    doublylist dlist;
    dlist.addAtEnd(10);
    dlist.addAtEnd(20);
    dlist.addAtEnd(30);
    dlist.print();

    cout << "Searching for 20: " << (dlist.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 40: " << (dlist.search(40) ? "Found" : "Not Found") << endl;

    dlist.deleteFromStart();
    dlist.print();

    return 0;
}