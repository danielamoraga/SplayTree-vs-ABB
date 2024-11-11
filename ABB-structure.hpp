#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

/* Árbol Binario de Búsqueda clásico */
struct ABB {
    int size = 0;
    int* r;
    ABB* izq;  // vacío o r es mayor que todos los elementos de izq
    ABB* der;  // vacío o r es menor que todos los elementos de der

    ABB() : r(nullptr), izq(nullptr), der(nullptr) {}  // árbol vacío

    ~ABB() {
        if (r != nullptr) delete r;
        if (izq != nullptr) delete izq;
        if (der != nullptr) delete der;
    }

    bool search(int x) {
        ABB* current = this;
        while (current != nullptr) {
            if (x == *(current->r)) {
                return true;
            } else if (x < *(current->r)) {
                current = current->izq;
            } else {
                current = current->der;
            }
        }
        return false;
    }

    void insert(int x) {
        if (r == nullptr) {
            r = new int(x);
            size++;
            return;
        }

        ABB* current = this;
        while (true) {
            if (x < *(current->r)) {
                if (current->izq == nullptr) {
                    current->izq = new ABB();
                    current->izq->r = new int(x);
                    current->size++;
                    break;
                }
                current = current->izq;
            } else {
                if (current->der == nullptr) {
                    current->der = new ABB();
                    current->der->r = new int(x);
                    current->size++;
                    break;
                }
                current = current->der;
            }
        }
    }


    void display() {
        if (r == nullptr) return;
        cout << *r << " ";
        while (izq != nullptr || der != nullptr) {
            cout << endl;
            izq->display();
            der->display();
        }
    }
};
