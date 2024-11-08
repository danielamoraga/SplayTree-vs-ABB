#include "first-scenario.hpp"

// Insertar N enteros distintos de manera aleatoria en un ABB y un Splay Tree
void insert_sorted(vector<int> A, ABB* abb, SplayTree* st) {
    sort(A.begin(), A.end()); // desordenar el vector para insertar aleatoriamente
    //cout << "Vector A ordenado: {";
    //for (int i = 0; i < A.size()-1; i++) {
    //    cout << A[i] << ", ";
    //}
    //cout << A[A.size()-1];
    //cout << "}" << endl;
    for (int x : A) {
        //cout << "Insertando " << x << " en ABB" << endl;
        abb->insert(x);
        //cout << "Insertando " << x << " en Splay Tree" << endl;
        st->insert(x);
    }
}

void third_scenario(ABB* abb, SplayTree* st, vector<int> A, int N, int M, bool b) {
    insert_sorted(A, abb, st);
    searching(A, abb, st, M, b);
}