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

    int countNodes(Node* node) {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeafNodes(Node* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BinaryTree tree;

    tree.root = tree.createNode(1);
    tree.root->left = tree.createNode(2);
    tree.root->right = tree.createNode(3);
    tree.root->left->left = tree.createNode(4);
    tree.root->left->right = tree.createNode(5);
    tree.root->right->right = tree.createNode(6);

    cout << "Total Nodes: " << tree.countNodes(tree.root) << endl;
    cout << "Leaf Nodes: " << tree.countLeafNodes(tree.root) << endl;
    cout << "Height of Tree: " << tree.height(tree.root) << endl;

    return 0;
}