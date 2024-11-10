#include "first-scenario.hpp"

// Insertar N enteros distintos de manera aleatoria en un ABB y un Splay Tree
void insert_sorted(vector<int> A, ABB* abb, SplayTree* st) {
    sort(A.begin(), A.end()); // desordenar el vector para insertar aleatoriamente
    for (int x : A) {
        abb->insert(x);
        st->insert(x);
    }
}

void third_scenario(ABB* abb, SplayTree* st, vector<int> A, int N, int M, bool b) {
    insert_sorted(A, abb, st);
    searching(A, abb, st, M, b);
}