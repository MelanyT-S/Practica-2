#include <iostream>
#include "mi_libreria.h"

using namespace std;

int main() {
    int opcion = 0;

    do {
        cout << "PRACTICA 2        " << endl;
        cout << "Ingrese un problema o 0 para salir: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int monto;
            cout << "PROBLEMA 1" << endl;
            cout << "Ingrese la cantidad de dinero: ";
            cin >> monto;

            const int denoms[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
            int cantBilletes[10] = {0};
            int faltante = 0;

            descomponerDinero(monto, denoms, 10, cantBilletes, &faltante);

            for (int i = 0; i < 10; i++) {
                cout << *(denoms + i) << ":" << *(cantBilletes + i) << endl;
            }
            cout << "Faltante: " << faltante << endl;
            break;
        }
        case 3: {
            char cad1[100], cad2[100];
            cout << "PROBLEMA 3 " << endl;
            cout << "Ingrese la primera cadena: ";
            cin >> cad1;
            cout << "Ingrese la segunda cadena: ";
            cin >> cad2;

            if (compararCadenas(cad1, cad2)) {
                cout << "Resultado: VERDADERO (Las cadenas son iguales)" << endl;
            } else {
                cout << "Resultado: FALSO (Las cadenas son diferentes)" << endl;
            }
            break;
        }
        case 5: {
            int numero;
            char buffer[50];
            cout << "PROBLEMA 5 " << endl;
            cout << "Ingrese un numero entero: ";
            cin >> numero;

            enteroACadena(numero, buffer);
            cout << "Cadena devuelta por referencia: \"" << buffer << "\"" << endl;
            break;
        }
        case 7: {
            char orig[100], dest[100];
            cout << "\n--- PROBLEMA 7 ---" << endl;
            cout << "Ingrese una cadena de texto: ";
            cin >> orig;

            eliminarRepetidos(orig, dest);
            cout << "Original: " << orig << ". Sin repetidos: " << dest << "." << endl;
            break;
        }
        case 9: {
            int n;
            char cadenaNum[100];
            cout << "\n--- PROBLEMA 9 ---" << endl;
            cout << "Ingrese el valor de n (cifras por grupo): ";
            cin >> n;
            cout << "Ingrese la cadena de numeros: ";
            cin >> cadenaNum;

            int suma = sumarGrupos(cadenaNum, n);

            // Formato exacto requerido por la nota
            cout << "Original: " << cadenaNum << "." << endl;
            cout << "Suma: " << suma << "." << endl;
            break;
        }
        case 0:
            cout << "\nSaliendo del programa..." << endl;
            break;
        default:
            cout << "\nOpcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}