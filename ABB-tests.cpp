#include "ABB-structure.hpp"
#include <iostream>
using namespace std;

// testing
int main() {
    ABB* A = new ABB;
    A->insert(10);
    A->insert(4);
    A->insert(16);
    A->insert(1);
    A->insert(7);
    A->insert(13);
    A->insert(19);
    //    10
    //   /   \
    //  4    16
    // / \   / \
    // 1 7  13 19

    cout << "A: " << A->size << endl;
    cout << "    " << *(A->r) << endl;
    cout << "   /   \\" << endl;
    ABB* left = A->izq;
    ABB* right = A->der;
    cout << "  " << *(left->r) << "    " << *(right->r) << endl;
    cout << " / \\   / \\" << endl;
    ABB* left_left = left->izq;
    ABB* left_right = left->der;
    ABB* right_left = right->izq;
    ABB* right_right = right->der;
    cout << " " << *(left_left->r) << " " << *(left_right->r) << "  " << *(right_left->r) << " " << *(right_right->r) << endl;

    // testing search
    if (A->search(10) == 1 && A->search(4) == 1 &&
        A->search(16) == 1 && A->search(1) == 1 &&
        A->search(7) == 1 && A->search(13) == 1 &&
        A->search(19) == 1)
        printf("All elements found successfully\n");

    if (A->search(0) == 0 && A->search(2) == 0 &&
        A->search(5) == 0 && A->search(8) == 0 &&
        A->search(11) == 0 && A->search(14) == 0 &&
        A->search(17) == 0)
        printf("All elements not found successfully\n");

    // testing insert constructing A again
    //    10
    //   /   \
    //  4    16
    // / \   / \
    // 1 7  13 19
    ABB* B = new ABB;
    B->insert(10);
    B->insert(7);
    B->insert(19);
    B->insert(4);
    B->insert(1);
    B->insert(13);
    B->insert(16);

    //     10
    //     / \
    //    7  19
    //   /   /
    //  4   13
    // /      \
    //1       16

    cout << "B: " << B->size << endl;
    cout << "     " << *(B->r) << endl;
    cout << "     / \\" << endl;
    cout << "    " << *(B->izq->r) << "  " << *(B->der->r) << endl;
    cout << "   /   /" << endl;
    cout << "  " << *(B->izq->izq->r) << "   " << *(B->der->izq->r) << endl;
    cout << " /      \\" << endl;
    cout << *(B->izq->izq->izq->r) << "       " << *(B->der->izq->der->r) << endl;

    if (B->search(10) == 1 && B->search(4) == 1 &&
        B->search(16) == 1 && B->search(1) == 1 &&
        B->search(7) == 1 && B->search(13) == 1 &&
        B->search(19) == 1)
        printf("All elements found successfully\n");

    if (B->search(0) == 0 && B->search(2) == 0 &&
        B->search(5) == 0 && B->search(8) == 0 &&
        B->search(11) == 0 && B->search(14) == 0 &&
        B->search(17) == 0)
        printf("All elements not found successfully\n");

    return 0;
}