/* Árbol Binario de Búsqueda clásico */
struct ABB {
    int r;
    ABB* izq; // vacío o r es mayor que todos los elementos de izq
    ABB* der; // vacío o r es menor que todos los elementos de der

    bool search(int x) {
        if (x == r) return true;
        if (x < r) {
            if (izq == nullptr) return false;
            else izq->search(x);
        }
        if (x > r) {
            if (der == nullptr) return false;
            else der->search(x);
        }
        return false;
    }
};