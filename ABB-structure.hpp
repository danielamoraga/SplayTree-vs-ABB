#include <iostream>
#include <stack>
using namespace std;

/* Árbol Binario de Búsqueda clásico adaptado */
struct ABBNode {
    int value;
    ABBNode* left;
    ABBNode* right;
    ABBNode* parent;

    ABBNode(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

struct ABB {
    ABBNode* root;
    int size;

    ABB() : root(nullptr), size(0) {}

    ~ABB() {
        destroyTree(root);
    }

    void destroyTree(ABBNode* ABBNode) {
        if (ABBNode) {
            destroyTree(ABBNode->left);
            destroyTree(ABBNode->right);
            delete ABBNode;
        }
    }

    // Inserción iterativa
    void insert(int val) {
        if (!root) {
            root = new ABBNode(val);
            size++;
            return;
        }

        ABBNode* current = root;
        ABBNode* parent = nullptr;

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

        ABBNode* newNode = new ABBNode(val);
        if (val < parent->value) parent->left = newNode;
        else parent->right = newNode;

    }

    // Búsqueda iterativa
    bool search(int val) {
        ABBNode* current = root;

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
    void display(ABBNode* ABBNode = nullptr) const {
        if (!ABBNode) ABBNode = root;
        if (!ABBNode) return;

        cout << ABBNode->value << " ";
        if (ABBNode->left) display(ABBNode->left);
        if (ABBNode->right) display(ABBNode->right);
    }
};
