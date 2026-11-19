#include <iostream>
#include "mi_libreria.h"

using namespace std;

int main() {
    int opcion = 0;

    do {
        cout << "PRACTICA 2" << endl;
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
            cout << "PROBLEMA 7 " << endl;
            cout << "Ingrese una cadena de texto: ";
            cin >> orig;

            eliminarRepetidos(orig, dest);
            cout << "Original: " << orig << ". Sin repetidos: " << dest << "." << endl;
            break;
        }
        case 9: {
            int n;
            char cadenaNum[100];
            cout << "PROBLEMA 9" << endl;
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
        case 11: {
            const int FILAS = 15;
            const int COLS = 20;
            char sala[FILAS][COLS];

            // Inicializa todos los asientos como disponibles ('-')
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLS; j++) {
                    *(*(sala + i) + j) = '-';
                }
            }

            int subOp = -1;
            do {
                cout << "\nPROBLEMA 11 - SALA DE CINE" << endl;
                mostrarSala(sala, FILAS, COLS);
                cout << "1. Reservar asiento | 2. Cancelar reserva | 0. Volver al menu: ";
                cin >> subOp;

                if (subOp == 1 || subOp == 2) {
                    char fila;
                    int asiento;
                    cout << "Ingrese fila (A-O): ";
                    cin >> fila;
                    cout << "Ingrese asiento (1-20): ";
                    cin >> asiento;

                    bool ok = gestionarReserva(sala, FILAS, COLS, fila, asiento, subOp == 1);
                    if (ok) {
                        cout << "Operacion realizada con exito." << endl;
                    } else {
                        cout << "No se pudo realizar la operacion (ocupado/libre o fuera de rango)." << endl;
                    }
                }
            } while (subOp != 0);
            break;
        }
        case 13: {
            int filas, cols;
            cout << "PROBLEMA 13" << endl;
            cout << "Ingrese el numero de filas: ";
            cin >> filas;
            cout << "Ingrese el numero de columnas: ";
            cin >> cols;

            if (filas <= 0 || cols <= 0) {
                cout << "Dimensiones invalidas." << endl;
                break;
            }

            // Reserva dinamica de memoria para la matriz recibida como puntero
            int *matriz = new int[filas * cols];

            cout << "Ingrese los valores de la matriz (" << (filas * cols) << " enteros):" << endl;
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < cols; j++) {
                    cin >> *(matriz + i * cols + j);
                }
            }

            // Muestra como quedo formada la matriz en filas y columnas
            cout << "\nMatriz ingresada:" << endl;
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << *(matriz + i * cols + j) << "\t";
                }
                cout << endl;
            }

            int totalEstrellas = contarEstrellas(matriz, filas, cols);
            cout << "\nEstrellas encontradas (sin bordes): " << totalEstrellas << endl;

            // Libera la memoria reservada
            delete[] matriz;
            break;
        }
        case 15: {
            int rectA[4], rectB[4], rectC[4];
            cout << "PROBLEMA 15" << endl;
            cout << "Ingrese rectangulo A (x y ancho alto): ";
            for (int i = 0; i < 4; i++) cin >> *(rectA + i);

            cout << "Ingrese rectangulo B (x y ancho alto): ";
            for (int i = 0; i < 4; i++) cin >> *(rectB + i);

            intersectarRectangulos(rectA, rectB, rectC);

            cout << "Interseccion C: {"
                 << *(rectC + 0) << ", " << *(rectC + 1) << ", "
                 << *(rectC + 2) << ", " << *(rectC + 3) << "}" << endl;
            break;
        }
        case 17: {
            int limite;
            cout << "PROBLEMA 17" << endl;
            cout << "Ingrese un numero limite: ";
            cin >> limite;

            int resultado = sumaAmigablesMenores(limite);
            cout << "El resultado de la suma es: " << resultado << "." << endl;
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