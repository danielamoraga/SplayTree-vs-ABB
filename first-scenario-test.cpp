#include "first-scenario.hpp"
#include <math.h>
#include <chrono>
using namespace chrono;

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
    return A;
}

int main() {
    int b = true;
    ABB* abb = new ABB;
    SplayTree* st = new SplayTree;
    
    int N = 5;
    int M = 2 * N;

    vector<int> A = random_vector(N);
    
    auto start = high_resolution_clock::now();
    first_scenario(abb, st, A, N, M, b);
    if (b == true) cout << "Todas las búsquedas fueron exitosas." << endl;
    auto end = high_resolution_clock::now();
    double time = duration_cast<nanoseconds>(end - start).count();
    cout << "Tiempo de ejecución : " << time << "ns" << endl;

    return 0;
}