/* Splay Tree */
struct SplayTree {
    int r;
    SplayTree* izq;
    SplayTree* der;

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

    void splay(int x){}

};