#include <iostream>
using namespace std;

class nodeInt {
public:
    int data;
    nodeInt* next;

    nodeInt(int val) : data(val), next(nullptr) {}
};

class nodeStr {
public:
    string data;
    nodeStr* next;

    nodeStr(string str) : data(str), next(nullptr) {}
};

class linkedList {
private:
    nodeStr* head;
public:
    linkedList() : head(nullptr) {}

    ~linkedList() {
        nodeStr* current = head;
        while (current) {
            nodeStr* nextnodeInt = current->next;
            delete current;
            current = nextnodeInt;
        }
    }

    void addAtStart(string value) {
        if (!head) {
            head = new nodeStr(value);
            return;
        }
        nodeStr* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new nodeStr(value);
    }

    void AddAtEnd(string value) {
        nodeStr* newNode = new nodeStr(value);
        if (!head) {
            head = newNode;
            return;
        }
        nodeStr* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void print() {
        cout<<"Linked List: ";
        nodeStr* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout<<"null"<< endl;
    }

    bool search(string value) {
        nodeStr* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void addAfter(string target, string value) {
        nodeStr* current = head;
        while (current) {
            if (current->data == target) {
                nodeStr* newNode = new nodeStr(value);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    linkedList list;
    list.addAtStart("Artificial intelligence");
    list.addAtStart("operating systems");
    list.AddAtEnd("Machine Learning");
    list.addAfter("operating systems","cyber security");

    list.print();

    if(list.search("DataBase systems"))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}