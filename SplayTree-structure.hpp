using namespace std;

/* Splay Tree */
struct SplayTree {
    int r;
    SplayTree* izq;
    SplayTree* der;

    private:

    // Rotación derecha
    void zig() {
        SplayTree* x = this->izq;
        this->izq = x->der;
        x->der = this;
    }

    // Rotación izquierda
    void zag() {
        SplayTree* x = this->der;
        this->der = x->izq;
        x->izq = this;
    }

    void zigzig() {
        if (izq) izq->zig();
        zig();
    }

    void zagzag() {
        if (der) der->zag();
        zag();
    }

    void zigzag() {
        if (this->izq) this->izq->zag();
        zig();
    }

    void zagzig() {
        if (this->der) this->der->zig();
        zag();
    }

    void splay(int x) {
        if (this == nullptr || this->r == x) return;

        if (x < this->r) { // Caso: `x` está en el subárbol izquierdo
            if (this->izq == nullptr) return;

            if (x < this->izq->r) { // Zig-Zig
                this->izq->splay(x);
                zigzig();
            } else if (x > this->izq->r) { // Zig-Zag
                this->izq->der->splay(x);
                zigzag();
            } else {
                zig();
            }
        } else { // Caso: `x` está en el subárbol derecho
            if (this->der == nullptr) return;

            if (x > this->der->r) { // Zag-Zag
                this->der->splay(x);
                zagzag();
            } else if (x < this->der->r) { // Zag-Zig
                this->der->izq->splay(x);
                zagzig();
            } else {
                zag();
            }
        }
    }

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