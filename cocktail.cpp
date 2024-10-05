#include <iostream>

// Función para intercambiar los valores a los que apuntan dos punteros
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementación de Cocktail Sort usando punteros
void cocktailSort(int* arr, int size) {
    bool swapped = true;
    int* start = arr;            // Puntero al inicio del array
    int* end = arr + size - 1;   // Puntero al final del array

    while (swapped) {
        swapped = false;

        // Recorrido de izquierda a derecha usando punteros
        for (int* i = start; i < end; ++i) {
            if (*i > *(i + 1)) {
                swap(i, i + 1);
                swapped = true;
            }
        }

        // Si no hubo intercambio, la lista ya está ordenada
        if (!swapped) {
            break;
        }

        // Restablecer swapped a false para la siguiente pasada
        swapped = false;
        // Reducir el final ya que el último elemento ya está ordenado
        --end;

        // Recorrido de derecha a izquierda usando punteros
        for (int* i = end - 1; i >= start; --i) {
            if (*i > *(i + 1)) {
                swap(i, i + 1);
                swapped = true;
            }
        }

        // Aumentar el inicio ya que el primer elemento ya está ordenado
        ++start;
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    cocktailSort(arr, size);

    std::cout << "Array ordenado: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
