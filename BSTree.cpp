#include "BSTree.h"
#include <iostream>
#include <algorithm>

BSTree::BSTree() : root(nullptr) {}

BSTree::~BSTree() {
    clear(root);
}

void BSTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BSTree::insert(const std::string& value) {
    insert(root, value);
}

void BSTree::insert(Node*& node, const std::string& value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    } else {
        node->count++;
    }
}

bool BSTree::search(const std::string& value) const {
    return search(root, value);
}

bool BSTree::search(Node* node, const std::string& value) const {
    if (!node) return false;
    if (value == node->data) return true;
    if (value < node->data) return search(node->left, value);
    return search(node->right, value);
}

std::string BSTree::largest() const {
    Node* node = findMax(root);
    return node ? node->data : "";
}

std::string BSTree::smallest() const {
    Node* node = findMin(root);
    return node ? node->data : "";
}

Node* BSTree::findMin(Node* node) const {
    while (node && node->left) node = node->left;
    return node;
}

Node* BSTree::findMax(Node* node) const {
    while (node && node->right) node = node->right;
    return node;
}

int BSTree::height(const std::string& value) const {
    Node* n = findNode(root, value);
    if (!n) return -1;
    return height(n);
}

Node* BSTree::findNode(Node* node, const std::string& value) const {
    if (!node) return nullptr;
    if (value == node->data) return node;
    if (value < node->data) return findNode(node->left, value);
    return findNode(node->right, value);
}

int BSTree::height(Node* node) const {
    if (!node) return -1;
    int l = height(node->left);
    int r = height(node->right);
    return 1 + std::max(l, r);
}

void BSTree::remove(const std::string& value) {
    remove(root, value);
}

void BSTree::remove(Node*& node, const std::string& value) {
    if (!node) return;

    if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        if (node->count > 1) {
            node->count--;
        } else {
            if (!node->left && !node->right) {
                delete node;
                node = nullptr;
            } else if (node->left) {
                Node* pred = findMax(node->left);
                node->data = pred->data;
                node->count = pred->count;
                pred->count = 1;
                remove(node->left, pred->data);
            } else {
                Node* succ = findMin(node->right);
                node->data = succ->data;
                node->count = succ->count;
                succ->count = 1;
                remove(node->right, succ->data);
            }
        }
    }
}

void BSTree::preOrder() const {
    preOrder(root);
    std::cout << std::endl;
}

void BSTree::preOrder(Node* node) const {
    if (!node) return;
    std::cout << node->data << "(" << node->count << "), ";
    preOrder(node->left);
    preOrder(node->right);
}

void BSTree::inOrder() const {
    inOrder(root);
    std::cout << std::endl;
}

void BSTree::inOrder(Node* node) const {
    if (!node) return;
    inOrder(node->left);
    std::cout << node->data << "(" << node->count << "), ";
    inOrder(node->right);
}

void BSTree::postOrder() const {
    postOrder(root);
    std::cout << std::endl;
}

void BSTree::postOrder(Node* node) const {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << "(" << node->count << "), ";
}