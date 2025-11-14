#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
public:
    int key, height;
    AVLTree* left;
    AVLTree* right;

    AVLTree(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

int h(AVLTree* n) { return n ? n->height : 0; }
int bal(AVLTree* n) { return n ? h(n->left) - h(n->right) : 0; }

AVLTree* rightRotate(AVLTree* y) {
    AVLTree* x = y->left;
    AVLTree* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

AVLTree* leftRotate(AVLTree* x) {
    AVLTree* y = x->right;
    AVLTree* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

AVLTree* insertNode(AVLTree* node, int key) {
    if (!node) return new AVLTree(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);
    else return node;

    node->height = max(h(node->left), h(node->right)) + 1;
    int b = bal(node);

    if (b > 1 && key < node->left->key) return rightRotate(node);
    if (b < -1 && key > node->right->key) return leftRotate(node);
    if (b > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (b < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preorder(AVLTree* r) {
    if (!r) return;
    cout << r->key << " ";
    preorder(r->left);
    preorder(r->right);
}

int main() {
    AVLTree* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    root = insertNode(root, 55);

    root = leftRotate(root);

    preorder(root);
    cout << endl;
}
