#include <iostream>
#include "mi_libreria.h"

using namespace std;

int main() {
    int monto;
    cout << "Ingrese la cantidad de dinero: ";
    cin >> monto; // Entrada dinámica del usuario

    const int denoms[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantBilletes[10] = {0};
    int faltante = 0;

    // Se pasa la dirección de memoria de faltante con &
    descomponerDinero(monto, denoms, 10, cantBilletes, &faltante);

    for (int i = 0; i < 10; i++) {
        cout << *(denoms + i) << ":" << *(cantBilletes + i) << endl;
    }
    cout << "Faltante: " << faltante << endl;

    return 0;
}