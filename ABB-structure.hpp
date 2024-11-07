/* Árbol Binario de Búsqueda clásico */
struct ABB {
    int r;
    ABB* izq; // vacío o r es mayor que todos los elementos de izq
    ABB* der; // vacío o r es menor que todos los elementos de der

    bool search(int x) {
        if (x == r) return true;
        else if (x < r) return izq != nullptr && izq->search(x);
        else if (x > r) return der != nullptr && der->search(x);
    }
};