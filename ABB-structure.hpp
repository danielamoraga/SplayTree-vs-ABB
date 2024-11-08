#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

/* Árbol Binario de Búsqueda clásico */
struct ABB {
    int size = 0;
    int* r;
    ABB* izq; // vacío o r es mayor que todos los elementos de izq
    ABB* der; // vacío o r es menor que todos los elementos de der

    ABB() : r(nullptr), izq(nullptr), der(nullptr) {} // árbol vacío

    bool search(int x) {
        if (r == nullptr) return false;
        if (x == *r) return true;
        else if (x < *r) return izq != nullptr && izq->search(x);
        else return der != nullptr && der->search(x);
        return false;
    }

    void insert(int x) {
        if (r == nullptr) {
            r = new int(x);
            size++;
        }
        else if (x < *r) {
            if (izq == nullptr) izq = new ABB();
            izq->insert(x);
            size++;
        }
        else {
            if (der == nullptr) der = new ABB();
            der->insert(x);
            size++;
        }
    }

    void display() {
        if (r == nullptr) return;
        cout << *r << " ";
        while (izq != nullptr || der!= nullptr) {
            cout << endl;
            izq->display();
            der->display();
        }
    }
};