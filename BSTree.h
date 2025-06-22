#pragma once
#include <string>
#include "Node.h"

class BSTree {
public:
    BSTree();
    ~BSTree();

    void insert(const std::string&);
    bool search(const std::string&) const;
    std::string largest() const;
    std::string smallest() const;
    int height(const std::string&) const;
    void remove(const std::string&);

    void preOrder() const;
    void inOrder() const;
    void postOrder() const;

private:
    Node* root;

    void clear(Node* node);

    // Recursive helpers
    void insert(Node*& node, const std::string&);
    bool search(Node* node, const std::string&) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    Node* findNode(Node* node, const std::string&) const;
    int height(Node* node) const;
    void remove(Node*& node, const std::string&);

    void preOrder(Node* node) const;
    void inOrder(Node* node) const;
    void postOrder(Node* node) const;
};