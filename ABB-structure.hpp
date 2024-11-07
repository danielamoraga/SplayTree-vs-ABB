/* Árbol Binario de Búsqueda clásico */
struct ABB {
    int root;
    ABB* izq; // vacío o root es mayor que todos los elementos de izq
    ABB* der; // vacío o root es menor que todos los elementos de der
};