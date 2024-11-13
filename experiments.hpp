#include <math.h>
#include <algorithm>
#include <map>
#include <random>

// Genera un vector con N elementos distintos
vector<int> create_random_vector(int N) {
    cout << "Creando vector..." << endl;

    // Generar una secuencia de números únicos de 1 a N
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;  // Llenar con valores únicos
    }

    // Mezclar la secuencia de valores únicos para hacerla aleatoria
    auto rng = default_random_engine{};
    shuffle(A.begin(), A.end(), rng);

    return A;
}

// Inserta N enteros distintos en un ABB o un Splay Tree
template <typename Tree>
void insert_elements(vector<int>& A, Tree* t) {
    for (int x : A) {
        t->insert(x);
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
    auto rng = default_random_engine{};
    int N = A.size();
    // buscar v[i] M/N veces
    vector<int> B;  // valores a buscar
    int copias = M / N;

    for (int val : A) {
        for (int i = 0; i < copias; i++) {
            B.push_back(val);
        }
    }

    shuffle(B.begin(), B.end(), rng);  // permutación aleatoria de B
    return B;
}

// Genera el vector B con búsquedas sesgadas
vector<int> create_biased_B(vector<int>& A, int M) {
    auto rng = default_random_engine{};
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

    shuffle(B.begin(), B.end(), rng);  // permutación aleatoria de B
    return B;
}

// Hace M búsquedas por valores escogidos entre los elementos insertados
template <typename Tree>
void search_elements(vector<int>& B, Tree* t) {
    for (int x : B) {
        t->search(x);
    }
}

template <typename Tree>
void execute_scenario(int scenario, Tree* t, vector<int>& A, int M) {
    vector<int> B;
    auto rng = default_random_engine{};
    switch (scenario) {
        case 1:
            shuffle(A.begin(), A.end(), rng);  // desordenar el vector para insertar aleatoriamente
            insert_elements(A, t);
            B = create_B(A, M);
            search_elements(B, t);
            break;

        case 2:
            shuffle(A.begin(), A.end(), rng);  // desordenar el vector para insertar aleatoriamente
            insert_elements(A, t);
            B = create_biased_B(A, M);
            search_elements(B, t);
            break;

        case 3:
            sort(A.begin(), A.end());  // antes de insertar los elementos, se ordena A
            insert_elements(A, t);
            B = create_B(A, M);
            search_elements(B, t);
            break;

        case 4:
            shuffle(A.begin(), A.end(), rng);  // desordenar el vector para insertar aleatoriamente
            vector<int> C = A;
            sort(C.begin(), C.end());
            insert_elements(C, t);
            B = create_biased_B(C, M);
            search_elements(B, t);
            break;
    }
}