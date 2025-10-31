#include <iostream>
#include <string>
using namespace std;

class TourPackage {
public:
    string name;
    TourPackage* left;
    TourPackage* right;

    TourPackage(string n) {
        name = n;
        left = right = nullptr;
    }
};

class TourTree {
private:
    TourPackage* root;

    void display(TourPackage* node, int space) {
        if (node == nullptr) return;
        space += 5;
        display(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << node->name << endl;
        display(node->left, space);
    }

    TourPackage* add(TourPackage* node, string parent, string name, char side) {
        if (node == nullptr) return nullptr;
        if (node->name == parent) {
            if (side == 'L' && node->left == nullptr)
                node->left = new TourPackage(name);
            else if (side == 'R' && node->right == nullptr)
                node->right = new TourPackage(name);
            else
                cout << "Cannot add. Child already exists.\n";
            return node;
        }
        add(node->left, parent, name, side);
        add(node->right, parent, name, side);
        return node;
    }

public:
    TourTree() {
        root = nullptr;
    }

    void createRoot(string name) {
        if (root == nullptr)
            root = new TourPackage(name);
        else
            cout << "Root already exists.\n";
    }

    void addPackage(string parent, string name, char side) {
        if (root == nullptr) {
            cout << "Create root first.\n";
            return;
        }
        add(root, parent, name, side);
    }

    void displayTree() {
        if (root == nullptr) cout << "No packages to display.\n";
        else display(root, 0);
    }
};

int main() {
    TourTree tree;
    int choice;
    string name, parent;
    char side;

    cout << "===== TOUR PACKAGE MANAGEMENT SYSTEM =====\n";
    do {
        cout << "\n1. Create Root Package"
             << "\n2. Add New Package (under a parent)"
             << "\n3. Display All Packages"
             << "\n4. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter root package name: ";
            getline(cin, name);
            tree.createRoot(name);
            break;
        case 2:
            cout << "Enter parent package name: ";
            getline(cin, parent);
            cout << "Enter new package name: ";
            getline(cin, name);
            cout << "Enter side (L/R): ";
            cin >> side;
            cin.ignore();
            tree.addPackage(parent, name, side);
            break;
        case 3:
            tree.displayTree();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
