#include "ABB-structure.hpp"
#include <iostream>
using namespace std;

// testing
int main() {
    ABB* A = new ABB{10, new ABB{4, new ABB{1, nullptr, nullptr}, new ABB{7, nullptr, nullptr}}, new ABB{16, new ABB{13, nullptr, nullptr}, new ABB{19, nullptr, nullptr}}};
    //    10
    //   /   \
    //  4    16
    // / \   / \
    // 1 7  13 19

    cout << A->search(10) << endl; // 1
    cout << A->search(4) << endl; // 1
    cout << A->search(16) << endl; // 1
    cout << A->search(1) << endl; // 1
    cout << A->search(7) << endl; // 1
    cout << A->search(13) << endl; // 1
    cout << A->search(19) << endl; // 1

    return 0;
}