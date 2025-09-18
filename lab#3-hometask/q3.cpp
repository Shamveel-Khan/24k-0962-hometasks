#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;

    Node(int i, string n, int p) {
        id = i;
        name = n;
        price = p;
        prev = nullptr;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;
    Node* tail;

public:
    ShoppingCart() {
        head = nullptr;
        tail = nullptr;
    }

    void insertEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void removeEnd() {
        if (!tail) {
            cout << "Cart is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Found: " << temp->id << " " << temp->name << " $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                cout << "Updated: " << temp->id << " " << temp->name << " $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    void displayForward() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Node* temp = head;
        cout << "Cart (Front -> End):\n";
        while (temp) {
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (!tail) {
            cout << "Cart is empty\n";
            return;
        }
        Node* temp = tail;
        cout << "Cart (End -> Front):\n";
        while (temp) {
            cout << temp->id << " " << temp->name << " $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    void countItems() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << "Total items: " << count << endl;
    }

    void mostExpensive() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Node* temp = head;
        Node* maxItem = head;
        while (temp) {
            if (temp->price > maxItem->price) maxItem = temp;
            temp = temp->next;
        }
        cout << "Most Expensive: " << maxItem->id << " " << maxItem->name << " $" << maxItem->price << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.insertEnd(1, "Laptop", 1000);
    cart.insertEnd(2, "Phone", 700);
    cart.insertEnd(3, "Tablet", 400);
    cart.insertEnd(4, "Headphones", 150);

    cart.displayForward();
    cout << "---\n";

    cart.insertFront(5, "Smartwatch", 200);
    cart.displayForward();
    cout << "---\n";

    cart.removeFront();
    cart.removeEnd();
    cart.displayForward();
    cout << "---\n";

    cart.searchByID(2);
    cart.updatePrice(2, 750);
    cart.displayForward();
    cout << "---\n";

    cart.displayBackward();
    cout << "---\n";

    cart.countItems();
    cart.mostExpensive();

    return 0;
}