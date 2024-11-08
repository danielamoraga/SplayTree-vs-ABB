using namespace std;

/* Splay Tree */
struct SplayTree {
    int r;
    SplayTree* izq;
    SplayTree* der;

    private:

    // Rotación derecha
    SplayTree* zig(SplayTree* y) {
        SplayTree* x = y->izq;
        y->izq = x->der;
        x->der = y;
        return x;
    }

    // Rotación izquierda
    SplayTree* zag(SplayTree* y) {
        SplayTree* x = y->der;
        y->der = x->izq;
        x->izq = y;
        return x;
    }

    SplayTree* zigzig(SplayTree* z) {
        SplayTree* y = zig(z);
        SplayTree* x = zig(y);
        return x;
    }

    void splay(int x){}

    public:

    bool search(int x) {
        /* buscar x como en ABB */
        if (x == r) {
            splay(x);
            return true;
        }
        else if (x < r){
            if (izq == nullptr){
                splay(r); // splay del que debería ser el parent de x
                return false;
            }
            return izq->search(x);
        }
        else if (x > r) {
            if (der == nullptr){
                splay(r); // splay del que debería ser el parent de x
                return false;
            }
        }
        return der->search(x);
    }

    void insert(int x) {}
};