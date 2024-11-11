using namespace std;

/* Splay Tree */
struct SplayTree {
    int* r;
    SplayTree* izq;
    SplayTree* der;

    SplayTree() : r(nullptr), izq(nullptr), der(nullptr) {}

    ~SplayTree() {
        if (r != nullptr) delete r;
        if (izq != nullptr) delete izq;
        if (der != nullptr) delete der;
    }

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
        if (izq) izq->zag();
        zig();
    }

    void zagzig() {
        if (der) der->zig();
        zag();
    }

    void splay(int x) {
        if (r == nullptr || *r == x) return;

        if (x < *r) {  // Caso: `x` está en el subárbol izquierdo
            if (this->izq == nullptr) return;

            if (x < *this->izq->r) {  // Zig-Zig
                this->izq->splay(x);
                zigzig();
            }
            else if (x > *this->izq->r) {  // Zig-Zag
                this->izq->der->splay(x);
                zigzag();
            }
            else {
                zig();
            }
        }
        else {  // Caso: `x` está en el subárbol derecho
            if (this->der == nullptr) return;

            if (x > *this->der->r) {  // Zag-Zag
                this->der->splay(x);
                zagzag();
            }
            else if (x < *this->der->r) {  // Zag-Zig
                this->der->izq->splay(x);
                zagzig();
            }
            else {
                zag();
            }
        }
    }

   public:
    bool search(int x) {
        SplayTree* current = this;
        SplayTree* parent = nullptr;

        while (current != nullptr && current->r != nullptr) {
            if (x == *(current->r)) {
                current->splay(x);  // Lleva el nodo encontrado a la raíz
                return true;
            }
            parent = current;
            if (x < *(current->r)) {
                current = current->izq;
            } else {
                current = current->der;
            }
        }

        // Si no encontramos el valor, hacemos splay del nodo donde debería estar
        if (parent && parent->r != nullptr) {
            parent->splay(*(parent->r));
        }

        return false;
    }


    void insert(int x) {
        if (r == nullptr) {
            r = new int(x);
            splay(x);
            return;
        }

        SplayTree* current = this;
        while (true) {
            if (x < *(current->r)) {
                if (current->izq == nullptr) {
                    current->izq = new SplayTree();
                    current->izq->r = new int(x);
                    break;
                }
                current = current->izq;
            } else {
                if (current->der == nullptr) {
                    current->der = new SplayTree();
                    current->der->r = new int(x);
                    break;
                }
                current = current->der;
            }
        }

        splay(x);  // Llevar el elemento insertado a la raíz
    }

};
