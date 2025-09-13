#include <iostream>
using namespace std;    

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
        cout <<"null"<<endl;
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

    void deleteFromStart() {
        if (!head) return;
        nodeStr* temp = head;
        head = head->next;
        delete temp;
    }

    string serachByPosition(int position) {
        string value;
        if (position < 0) return "";
        nodeStr* current = head;
        int index = 0;
        while (current) {
            if (index == position) {
                value = current->data;
                return value;
            }
            current = current->next;
            index++;
        }
        return "";
    }
};


int main() {
    linkedList list;
    list.AddAtEnd("book1");
    list.AddAtEnd("book2");
    list.AddAtEnd("book3");

    list.deleteFromStart();
    list.print();

    if (list.search("book2")) {
        cout << "Found book2 in the list." << endl;
    }

    string value = list.serachByPosition(1);
    cout << "Element at position 1: " << value << endl;
    return 0;
}