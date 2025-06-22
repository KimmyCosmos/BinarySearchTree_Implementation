#pragma once
#include <string>

class Node {
public:
    std::string data;
    int count;
    Node* left;
    Node* right;

    Node(const std::string& data);
};