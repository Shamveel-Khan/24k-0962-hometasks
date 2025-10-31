#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }

    Node* createNode(int val) {
        return new Node(val);
    }

    int subtreeSum(Node* node) {
        if (node == nullptr) return 0;
        return node->data + subtreeSum(node->left) + subtreeSum(node->right);
    }

    bool findSubtree(Node* node, int target) {
        if (node == nullptr) return false;
        int sum = subtreeSum(node);
        if (sum == target) {
            display(node, 0);
            return true;
        }
        return findSubtree(node->left, target) || findSubtree(node->right, target);
    }

    void display(Node* node, int space) {
        if (node == nullptr) return;
        space += 5;
        display(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++) cout << " ";
        cout << node->data << endl;
        display(node->left, space);
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.createNode(5);
    tree.root->left = tree.createNode(3);
    tree.root->right = tree.createNode(8);
    tree.root->left->left = tree.createNode(2);
    tree.root->left->right = tree.createNode(4);
    tree.root->right->left = tree.createNode(6);
    tree.root->right->right = tree.createNode(10);

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    if (!tree.findSubtree(tree.root, target))
        cout << "No subtree found with sum " << target << "." << endl;

    return 0;
}
