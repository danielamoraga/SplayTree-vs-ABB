#include <fstream>
#include <iostream>

#include "ABB-structure.hpp"
#include "SplayTree-structure.hpp"
#include "experiments.hpp"

void test_scenario(int scenario, vector<int>& A, int N, int M, ofstream& file) {
    cout << "---Escenario " << scenario << "---" << endl;
    double time_abb, time_splay;

    // ABB
    cout << "--ABB--" << endl;
    ABB* abb = new ABB;
    time_abb = execute_scenario(scenario, abb, A, M);
    delete abb;

    // Splay Tree
    cout << "--Splay Tree--" << endl;
    SplayTree* st = new SplayTree;
    time_splay = execute_scenario(scenario, st, A, M);
    delete st;

    file << N << "," << M << "," << scenario << "," << time_abb << "," << time_splay << "\n";
    file.flush();
}

int main() {
    ofstream file("resultados_experimento.csv");
    file << "N,M,Escenario,Tiempo ABB (ns),Tiempo Splay Tree (ns)\n";
    file.flush();

    for (double i = 0.1; i < 1.0; i += 0.1) {
        cout << "---------------------" << endl;
        int N = pow(10, 6) * i;
        int M = 100 * N;
        cout << "N = 10^6 * " << i << endl;
        vector<int> A = create_random_vector(N);

        for (int scenario = 1; scenario <= 4; scenario++) {
            test_scenario(scenario, A, N, M, file);
        }
    }

    file.close();
    cout << "---------------------" << endl;
    cout << "Experimento terminado." << endl;

    return 0;
}
