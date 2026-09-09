#include "mi_libreria.h"

void descomponerDinero(int cantidad, const int *denominaciones, int tam, int *cantidades, int *faltante) {
    int restante = cantidad;
    for (int i = 0; i < tam; i++) {
        *(cantidades + i) = restante / *(denominaciones + i); // Uso estricto de punteros
        restante %= *(denominaciones + i);
    }
    *faltante = restante; // Asignación por desreferenciación
}