#include "experiments.hpp"
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

    for (double i = 0.1; i < 1.0; i+=0.1) {
        int N = pow(10, 6) * i;
        int M = 100 * N;

        vector<int> A = random_vector(N);

        auto start = high_resolution_clock::now();
        first_scenario(abb, st, A, M);
        auto end = high_resolution_clock::now();
        double first_time = duration_cast<nanoseconds>(end - start).count();
        cout << "Tiempo de ejecución del primer escenario: " << first_time << "ns" << endl;

        // second scenario

        start = high_resolution_clock::now();
        third_scenario(abb, st, A, M);
        end = high_resolution_clock::now();
        first_time = duration_cast<nanoseconds>(end - start).count();
        cout << "Tiempo de ejecución del tercer escenario: " << first_time << "ns" << endl;

        // fourth scenario
    }

    return 0;
}