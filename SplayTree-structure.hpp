// SplayTree-structure.hpp
#ifndef SPLAYTREE_STRUCTURE_HPP
#define SPLAYTREE_STRUCTURE_HPP

#include "Node.hpp"

struct SplayTree {
    Node* root;

    SplayTree() : root(nullptr) {}

    ~SplayTree() {
        destroyTree(root);
    }

   private:
    void destroyTree(Node* Node) {
        if (Node) {
            destroyTree(Node->left);
            destroyTree(Node->right);
            delete Node;
        }
    }
    // Implementación de las rotaciones simples
    void zig(Node* x) {
        Node* p = x->parent;
        if (!p) return;

        // Rotación derecha
        p->left = x->right;
        if (x->right) x->right->parent = p;

        x->right = p;
        x->parent = p->parent;
        p->parent = x;

        if (x->parent) {
            if (x->parent->left == p)
                x->parent->left = x;
            else
                x->parent->right = x;
        }
        else {
            root = x;
        }
    }

    void zag(Node* x) {
        Node* p = x->parent;
        if (!p) return;

        // Rotación izquierda
        p->right = x->left;
        if (x->left) x->left->parent = p;

        x->left = p;
        x->parent = p->parent;
        p->parent = x;

        if (x->parent) {
            if (x->parent->left == p)
                x->parent->left = x;
            else
                x->parent->right = x;
        }
        else {
            root = x;
        }
    }

    // Implementación de los casos de Splay usando zig y zag
    void zigzig(Node* x) {
        zig(x->parent);  // Primer zig en el parent
        zig(x);          // Segundo zig en x
    }

    void zagzag(Node* x) {
        zag(x->parent);  // Primer zag en el parent
        zag(x);          // Segundo zag en x
    }

    void zigzag(Node* x) {
        zig(x);  // Primer zig en x
        zag(x);  // Segundo zag en x
    }

    void zagzig(Node* x) {
        zag(x);  // Primer zag en x
        zig(x);  // Segundo zig en x
    }

    // Implementación del método Splay
    void splay(Node* x) {
        while (x != root) {  // Iterar hasta que x sea la raíz
            Node* p = x->parent;
            Node* g = p ? p->parent : nullptr;

            if (!p) {
                break;
            }
            else if (!g) {
                // cuando x es hijo directo de la raíz
                if (x == p->left) {
                    zig(x);
                }
                else {
                    zag(x);
                }
            }
            else if (x == p->left && p == g->left) {
                zigzig(x);
            }
            else if (x == p->right && p == g->right) {
                zagzag(x);
            }
            else if (x == p->left && p == g->right) {
                zigzag(x);
            }
            else if (x == p->right && p == g->left) {
                zagzig(x);
            }
        }
    }

   public:
    void insert(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }

        Node* current = root;
        Node* parent = nullptr;
        // primero se busca la posición para el nuevo nodo
        while (current) {
            parent = current;
            if (val < current->value) {
                current = current->left;
            }
            else if (val > current->value) {
                current = current->right;
            }
            else {
                splay(current);
                return;
            }
        }

        Node* newNode = new Node(val);
        newNode->parent = parent;

        if (val < parent->value) {
            parent->left = newNode;
        }
        else {
            parent->right = newNode;
        }

        splay(newNode);
    }

    bool search(int val) {
        Node* current = root;
        Node* lastVisited = nullptr;

        while (current) {
            lastVisited = current;
            if (val == current->value) {
                splay(current);
                return true;
            }
            else if (val < current->value) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (lastVisited) {
            splay(lastVisited);
        }
        return false;
    }
};

#endif