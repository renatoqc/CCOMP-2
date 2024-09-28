#include <iostream>
using namespace std;

bool par(int x){
    return !(x % 2);
}

bool inpar(int x){
    return (x % 2);
}

void split(int* inicio, int* fin, bool f(int x)){
    int *r = inicio;
    for (int *p = inicio; p <= fin; p++) {
        if (f(*p)) {
            int val = *p;
            for (int *s = p; s > r; s--) {
                *s = *(s - 1);
            }
            *r = val;
            r++;
        }
    }
}

int main(){
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Imprimir el arreglo original
    cout << "Array original: ";
    for (int* inicio = A; inicio <= A + 9; inicio++) {
        cout << *inicio << " ";
    }
    cout << endl;

    // Aplicar split con la función 'par'
    split(A, A + 9, par);

    // Imprimir el arreglo después de aplicar split
    cout << "Array después de split: ";
    for (int* inicio = A; inicio <= A + 9; inicio++) {
        cout << *inicio << " ";
    }
    cout << endl;

    return 0;
}