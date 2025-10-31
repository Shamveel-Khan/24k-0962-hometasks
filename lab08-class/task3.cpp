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

    bool isFull(Node* node) {
        if (node == nullptr) return true;
        if ((node->left == nullptr && node->right == nullptr)) return true;
        if (node->left && node->right)
            return isFull(node->left) && isFull(node->right);
        return false;
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.createNode(1);
    tree.root->left = tree.createNode(2);
    tree.root->right = tree.createNode(3);
    tree.root->left->left = tree.createNode(4);
    tree.root->left->right = tree.createNode(5);
    tree.root->right->left = tree.createNode(6);
    tree.root->right->right = tree.createNode(7);

    if (tree.isFull(tree.root))
        cout << "The tree is a full binary tree." << endl;
    else
        cout << "The tree is not a full binary tree." << endl;

    return 0;
}
