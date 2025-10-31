#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int quantity;
    Node* left;
    Node* right;
    Node(int pid, int qty) {
        id = pid;
        quantity = qty;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insert(Node* node, int pid, int qty) {
        if (node == nullptr) return new Node(pid, qty);
        if (pid < node->id)
            node->left = insert(node->left, pid, qty);
        else if (pid > node->id)
            node->right = insert(node->right, pid, qty);
        else
            node->quantity += qty;
        return node;
    }

    void addProduct(int pid, int qty) {
        root = insert(root, pid, qty);
    }

    Node* search(Node* node, int pid) {
        if (node == nullptr || node->id == pid) return node;
        if (pid < node->id) return search(node->left, pid);
        return search(node->right, pid);
    }

    Node* findMaxQuantity(Node* node, Node* maxNode = nullptr) {
        if (node == nullptr) return maxNode;
        if (maxNode == nullptr || node->quantity > maxNode->quantity)
            maxNode = node;
        maxNode = findMaxQuantity(node->left, maxNode);
        maxNode = findMaxQuantity(node->right, maxNode);
        return maxNode;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "Product ID: " << node->id << "  Quantity: " << node->quantity << endl;
        inorder(node->right);
    }
};

int main() {
    BST tree;

    tree.addProduct(50, 20);
    tree.addProduct(30, 15);
    tree.addProduct(70, 25);
    tree.addProduct(20, 10);
    tree.addProduct(40, 12);
    tree.addProduct(60, 30);
    tree.addProduct(80, 18);

    tree.addProduct(60, 5); 

    cout << "All Products:\n";
    tree.inorder(tree.root);

    int searchId = 40;
    Node* result = tree.search(tree.root, searchId);
    if (result)
        cout << "\nProduct " << searchId << " found with quantity: " << result->quantity << endl;
    else
        cout << "\nProduct " << searchId << " not found.\n";

    Node* maxNode = tree.findMaxQuantity(tree.root);
    if (maxNode)
        cout << "\nProduct with highest quantity: ID " << maxNode->id 
             << " (Quantity: " << maxNode->quantity << ")\n";

    return 0;
}
