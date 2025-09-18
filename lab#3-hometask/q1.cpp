#include <iostream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int price;
    Item* next;

    Item(string n, int p) {
        name = n;
        price = p;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Item* head;

public:
    ShoppingCart() {
        head = nullptr;
    }

    void addFront(string name, int price) {
        Item* newItem = new Item(name, price);
        newItem->next = head;
        head = newItem;
    }

    void addEnd(string name, int price) {
        Item* newItem = new Item(name, price);
        if (head == nullptr) {
            head = newItem;
            return;
        }
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
    }

    void insertAfter(string afterName, string name, int price) {
        Item* temp = head;
        while (temp != nullptr) {
            if (temp->name == afterName) {
                Item* newItem = new Item(name, price);
                newItem->next = temp->next;
                temp->next = newItem;
                return;
            }
            temp = temp->next;
        }
    }

    void search(string name) {
        Item* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << name << " exists in cart with price $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in cart!" << endl;
    }

    void display() {
        Item* temp = head;
        cout << "Shopping Cart:\n";
        while (temp != nullptr) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ShoppingCart cart;
    cart.addEnd("Laptop", 1000);
    cart.addEnd("Phone", 700);
    cart.addEnd("Tablet", 400);
    cart.addEnd("Headphones", 150);

    cart.addFront("Smartwatch", 200);
    cart.addEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);

    cart.search("Tablet");
    cart.display();

    return 0;
}
