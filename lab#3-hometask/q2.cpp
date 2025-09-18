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

    void addTail(string name, int price) {
        Item* newItem = new Item(name, price);
        if (!head) {
            head = newItem;
            return;
        }
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newItem;
    }

    void deleteFront() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Item* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string name) {
        Item* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << temp->name << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found\n";
    }

    void searchByPosition(int pos) {
        Item* temp = head;
        int count = 1;
        while (temp) {
            if (count == pos) {
                cout << temp->name << " - $" << temp->price << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Position " << pos << " not found\n";
    }

    void display() {
        if (!head) {
            cout << "Cart is empty\n";
            return;
        }
        Item* temp = head;
        cout << "Shopping Cart:\n";
        while (temp) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ShoppingCart cart;
    cart.addTail("Laptop", 1000);
    cart.addTail("Phone", 700);
    cart.addTail("Tablet", 400);
    cart.addTail("Headphones", 150);

    cart.display();
    cout << "---\n";

    cart.deleteFront();
    cart.display();
    cout << "---\n";

    cart.searchByName("Tablet");
    cart.searchByPosition(2);

    return 0;
}