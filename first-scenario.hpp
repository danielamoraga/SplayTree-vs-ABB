#include "ABB-structure.hpp"
#include "SplayTree-structure.hpp"
#include <algorithm>
#include <map>

/* Experimentación */

// Genera un vector con N elementos distintos
vector<int> random_vector(int N) {
    vector<int> A(N);
    map<int,int> m;
    for (int i = 0; i < N; i++) {
        int x = 1 + rand() % 100; // [1, 100]
        if(m.find(i) == m.end()) {
            A[i] = x;
            m[x] = 1;
        } else i--;
    }
    //cout << "Vector A generado: {" ;
    //for (int i = 0; i < N-1; i++) {
    //    cout << A[i] << ", ";
    //}
    //cout << A[N-1];
    //cout << "}" << endl;
    return A;
}

// Insertar N enteros distintos de manera aleatoria en un ABB y un Splay Tree
void insert_random(vector<int> A, ABB* abb, SplayTree* st) {
    random_shuffle(A.begin(), A.end()); // desordenar el vector para insertar aleatoriamente
    //cout << "Vector A aleatorizado: {";
    //for (int i = 0; i < A.size()-1; i++) {
        //cout << A[i] << ", ";
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

// Hacer M búsquedas por valores escogidos entre los elementos insertados
void searching(vector<int> A, ABB* abb, SplayTree* st, int M, bool b) {
    int N = A.size();
    // buscar v[i] M/N veces
    vector<int> B; // valores a buscar
    int copias = M/N;

    for (int val : A) {
        for (int i = 0; i < copias; i++) {
            B.push_back(val);
        }
    }
    //cout << "Vector B generado: {" ;
    //for (int i = 0; i < B.size()-1; i++) {
    //    cout << B[i] << ", ";
    //}
    //cout << B[B.size()-1];
    //cout << "}" << endl;

    random_shuffle(B.begin(), B.end()); // permutación aleatoria de B
    //cout << "Vector B aleatorizado: {" ;
    //for (int i = 0; i < B.size()-1; i++) {
    //    cout << B[i] << ", ";
    //}
    //cout << B[B.size()-1];
    //cout << "}" << endl;

    for (int x : B) {
        //cout << "Buscando " << x << " en ABB..." << endl;
        abb->search(x);
        if (abb->search(x)) {
            b = true;
            //cout << "Búsqueda exitosa." << endl;
        }
        else {
            b = false;
            //cout << "Búsqueda infructuosa." << endl;
        }
        //cout << "Buscando " << x << " en Splay Tree..." << endl;
        //st->search(x);
        //if (st->search(x)) cout << "Búsqueda exitosa." << endl;
        //else cout << "Búsqueda infructuosa." << endl;
    }
}

void first_scenario(ABB* abb, SplayTree* st, int N, int M, bool b) {
    vector<int> A = random_vector(N);
    insert_random(A, abb, st);
    searching(A, abb, st, M, b);
}


// test pequeñito
/*
#include <math.h>
#include <chrono>
using namespace chrono;
int main() {
    int b = true;
    ABB* abb = new ABB;
    SplayTree* st = new SplayTree;
    
    int N = 5;
    int M = 2 * N;
    
    auto start = high_resolution_clock::now();
    first_scenario(abb, st, N, M, b);
    if (b == true) cout << "Todas las búsquedas fueron exitosas." << endl;
    auto end = high_resolution_clock::now();
    double first_time = duration_cast<nanoseconds>(end - start).count();
    cout << "Tiempo de ejecución del primer escenario: " << first_time << "ns" << endl;

    return 0;
}
*/