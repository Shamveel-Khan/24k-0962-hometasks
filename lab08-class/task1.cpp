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
    }

    void addPackage(string parent, string name, char side) {
        if (root == nullptr) return;
        add(root, parent, name, side);
    }

    void displayTree() {
        if (root == nullptr)
            cout << "No packages to display.\n";
        else
            display(root, 0);
    }
};

int main() {
    TourTree tree;

    tree.createRoot("World Tours");
    tree.addPackage("World Tours", "Europe Package", 'L');
    tree.addPackage("World Tours", "Asia Package", 'R');
    tree.addPackage("Europe Package", "France Tour", 'L');
    tree.addPackage("Europe Package", "Italy Tour", 'R');
    tree.addPackage("Asia Package", "Japan Tour", 'L');
    tree.addPackage("Asia Package", "India Tour", 'R');

    cout << "===== TOUR PACKAGE HIERARCHY =====\n";
    tree.displayTree();

    return 0;
}
