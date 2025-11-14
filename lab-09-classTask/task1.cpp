#include <iostream>
#include <algorithm>
using namespace std;

class AVL {
public:
    int key;
    int height;
    AVL* left;
    AVL* right;

    AVL(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

int h(AVL* n) {
    return n ? n->height : 0;
}

int balance(AVL* n) {
    return n ? h(n->left) - h(n->right) : 0;
}

AVL* rightRotate(AVL* y) {
    AVL* x = y->left;
    AVL* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(h(y->left), h(y->right)) + 1;
    x->height = max(h(x->left), h(x->right)) + 1;
    return x;
}

AVL* leftRotate(AVL* x) {
    AVL* y = x->right;
    AVL* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(h(x->left), h(x->right)) + 1;
    y->height = max(h(y->left), h(y->right)) + 1;
    return y;
}

AVL* insertNode(AVL* node, int key) {
    if (!node) return new AVL(key);
    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);
    else return node;

    node->height = max(h(node->left), h(node->right)) + 1;
    int b = balance(node);

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

void preorder(AVL* r) {
    if (!r) return;
    cout << r->key << " ";
    preorder(r->left);
    preorder(r->right);
}

int main() {
    AVL* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 15);

    preorder(root);
    cout << endl;
}
