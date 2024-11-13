// ABB-structure.hpp
#ifndef ABB_STRUCTURE_HPP
#define ABB_STRUCTURE_HPP

#include "Node.hpp"

/* Árbol Binario de Búsqueda clásico adaptado */
struct ABB {
    Node* root;
    int size;

    ABB() : root(nullptr), size(0) {}

    ~ABB() {
        destroyTree(root);
    }

    void destroyTree(Node* Node) {
        if (Node) {
            destroyTree(Node->left);
            destroyTree(Node->right);
            delete Node;
        }
    }

    // Inserción iterativa
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            size++;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (val < current->value) {
                current = current->left;
            } else if (val > current->value) {
                current = current->right;
            } else {
                // Si el valor ya existe, no se inserta de nuevo
                return;
            }
        }

        Node* newNode = new Node(val);
        if (val < parent->value) parent->left = newNode;
        else parent->right = newNode;

    }

    // Búsqueda iterativa
    bool search(int val) {
        Node* current = root;

        while (current) {
            if (val == current->value) {
                return true;
            } else if (val < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    // Mostrar árbol en preorden
    void display(Node* Node = nullptr) const {
        if (!Node) Node = root;
        if (!Node) return;

        cout << Node->value << " ";
        if (Node->left) display(Node->left);
        if (Node->right) display(Node->right);
    }
};

#endif