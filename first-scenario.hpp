#include "ABB-structure.hpp"
#include "SplayTree-structure.hpp"
#include <algorithm>
#include <map>

/* Experimentación */

// Insertar N enteros distintos de manera aleatoria en un ABB y un Splay Tree
void insert_random(vector<int> A, ABB* abb, SplayTree* st) {
    random_shuffle(A.begin(), A.end()); // desordenar el vector para insertar aleatoriamente
    for (int x : A) {
        abb->insert(x);
        st->insert(x);
    }
}

// Hacer M búsquedas por valores escogidos entre los elementos insertados
void searching(vector<int> A, ABB* abb, SplayTree* st, int M,  bool& b) {
    int N = A.size();
    // buscar v[i] M/N veces
    vector<int> B; // valores a buscar
    int copias = M/N;

    for (int val : A) {
        for (int i = 0; i < copias; i++) {
            B.push_back(val);
        }
    }

    random_shuffle(B.begin(), B.end()); // permutación aleatoria de B

    for (int x : B) {
        abb->search(x);
        if (abb->search(x)) b = true;
        else b = false;

        st->search(x);
        if (st->search(x)) b = true;
        else b = false;
    }
}

void first_scenario(ABB* abb, SplayTree* st, vector<int> A, int N, int M, bool b) {
    insert_random(A, abb, st);
    searching(A, abb, st, M, b);
}
