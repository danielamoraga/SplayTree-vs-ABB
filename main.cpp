#include "first-scenario.hpp"
#include <math.h>
#include <chrono>
using namespace chrono;

int main() {
    int b = true;
    ABB* abb = new ABB;
    SplayTree* st = new SplayTree;
    
    for (double i = 0.1; i < 1.0; i+=0.1) {
        int N = pow(10, 6) * i;
        int M = 100 * N;
        
        auto start = high_resolution_clock::now();
        first_scenario(abb, st, N, M, b);
        //if (b == true) cout << "Todas las búsquedas fueron exitosas." << endl;
        auto end = high_resolution_clock::now();
        double first_time = duration_cast<nanoseconds>(end - start).count();
        cout << "Tiempo de ejecución del primer escenario: " << first_time << "ns" << endl;
    }

    return 0;
}