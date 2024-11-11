#include <math.h>

#include <algorithm>
#include <map>
#include <random>

#include "ABB-structure.hpp"
#include "SplayTree-structure.hpp"

// Genera un vector con N elementos distintos
vector<int> create_random_vector(int N) {
    vector<int> A(N);
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int x = 1 + rand() % 100;  // [1, 100]
        if (m.find(x) == m.end()) {
            A[i] = x;
            m[x] = 1;
        }
        else
            i--;
    }
    return A;
}

// Inserta N enteros distintos en un ABB y un Splay Tree
void insert_in_trees(vector<int>& A, ABB* abb, SplayTree* st) {
    for (int x : A) {
        abb->insert(x);
        st->insert(x);
    }
}

// Calcula la constante C para normalizar la función de probabilidad
double compute_C(int N) {
    double suma = 0.0;
    for (int i = 0; i < N; i++) {
        suma += 1.0 / pow(i + 1, 2);
    }
    return 1.0 / suma;
}

// Calcula la función de probabilidad f
double f(int i, double C) {
    return C / pow(i + 1, 2);
}

// Genera el vector B con búsquedas uniformes
vector<int> create_B(vector<int>& A, int M) {
    int N = A.size();
    // buscar v[i] M/N veces
    vector<int> B;  // valores a buscar
    int copias = M / N;

    for (int val : A) {
        for (int i = 0; i < copias; i++) {
            B.push_back(val);
        }
    }

    random_shuffle(B.begin(), B.end());  // permutación aleatoria de B
    return B;
}

// Genera el vector B con búsquedas sesgadas
vector<int> create_biased_B(vector<int>& A, int M) {
    int N = A.size();
    double C = compute_C(N);
    vector<int> B;  // valores a buscar
    int copias;

    for (int i = 0; i < N; i++) {
        // buscar v[i] floor(M*f(i)) veces
        copias = floor(M * f(i, C));
        for (int j = 0; j < copias; j++) {
            B.push_back(A[i]);
        }
    }

    random_shuffle(B.begin(), B.end());  // permutación aleatoria de B
    return B;
}

// Hace M búsquedas por valores escogidos entre los elementos insertados
void search_test(vector<int>& B, ABB* abb, SplayTree* st) {
    for (int x : B) {
      abb->search(x);
      st->search(x);
    }
}

void first_scenario(ABB* abb, SplayTree* st, vector<int>& A, int M) {
    random_shuffle(A.begin(), A.end());  // desordenar el vector para insertar aleatoriamente
    insert_in_trees(A, abb, st);
    vector<int> B = create_B(A, M);
    search_test(B, abb, st);
}

void second_scenario(ABB* abb, SplayTree* st, vector<int>& A, int M) {
    random_shuffle(A.begin(), A.end());  // desordenar el vector para insertar aleatoriamente
    insert_in_trees(A, abb, st);
    vector<int> B = create_biased_B(A, M);
    search_test(B, abb, st);
}

void third_scenario(ABB* abb, SplayTree* st, vector<int>& A, int M) {
    sort(A.begin(), A.end());  // antes de insertar los elementos, se ordena A
    insert_in_trees(A, abb, st);
    vector<int> B = create_B(A, M);
    search_test(B, abb, st);
}

void fourth_scenario(ABB* abb, SplayTree* st, vector<int>& A, int M) {
    random_shuffle(A.begin(), A.end());  // desordenar el vector para insertar aleatoriamente
    vector<int> C = A;
    sort(C.begin(), C.end());
    insert_in_trees(C, abb, st);
    vector<int> B = create_biased_B(C, M);
    search_test(B, abb, st);
}