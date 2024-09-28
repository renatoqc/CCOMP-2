#include <iostream>

using namespace std;

void merge(int* p, int* q) {
    int* end = q + (q - p);
    int aux;
    for (int* i = p; i < end; i++) {
        for (int* j = i + 1; j < end; j++) {
            if (*j < *i) {
                aux = *i;
                *i = *j;
                *j = aux;
            }
        }
    }
}

int main() {
    int A[10]{ 2, 10, 8, 0, 30, 7, 97, 23, 63, 99 };
    int* x = A;
    int* y = A + 5;

    cout << "Array original: ";
    for (int* p = A; p < A + 10; p++) {
        cout << *p << "|";
    }
    cout << "\n";

    merge(x, y);

    cout << "Array después de merge: ";
    for (int* p = A; p < A + 10; p++) {
        cout << *p << "|";
    }
    cout << "\n";
}