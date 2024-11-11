#include <chrono>

#include "experiments.hpp"
using namespace chrono;

int main() {
    for (double i = 0.1; i < 1.0; i += 0.1) {
        int N = pow(10, 6) * i;
        int M = 100 * N;

        vector<int> A = create_random_vector(N);

        // first scenario
        ABB* abb = new ABB;
        SplayTree* st = new SplayTree;
        auto start = high_resolution_clock::now();
        first_scenario(abb, st, A, M);
        auto end = high_resolution_clock::now();
        double first_time = duration_cast<milliseconds>(end - start).count();
        cout << "Tiempo de ejecución del primer escenario: " << first_time << " ms" << endl;
        delete abb;
        delete st;

        // second scenario

        // Ejecutar Tercer Escenario
        abb = new ABB;
        st = new SplayTree;
        start = high_resolution_clock::now();
        third_scenario(abb, st, A, M);
        end = high_resolution_clock::now();
        double third_time = duration_cast<milliseconds>(end - start).count();
        cout << "Tiempo de ejecución del tercer escenario: " << third_time << " ms" << endl;
        delete abb;
        delete st;

        // fourth scenario
    }

    return 0;
}