// Node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

#endif