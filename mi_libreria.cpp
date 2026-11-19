#include "mi_libreria.h"
#include <iostream>

using namespace std;

// Problema 1
void descomponerDinero(int cantidad, const int *denominaciones, int tam, int *cantidades, int *faltante) {
    int restante = cantidad;
    for (int i = 0; i < tam; i++) {
        *(cantidades + i) = restante / *(denominaciones + i);
        restante %= *(denominaciones + i);
    }
    *faltante = restante;
}

// Problema 3
bool compararCadenas(const char *cad1, const char *cad2) {
    while (*cad1 != '\0' && *cad2 != '\0') {
        if (*cad1 != *cad2) return false;
        cad1++;
        cad2++;
    }
    return (*cad1 == '\0' && *cad2 == '\0');
}

// Problema 5
void enteroACadena(int numero, char *cadena) {
    char *pDest = cadena;
    bool esNegativo = false;

    if (numero == 0) {
        *pDest = '0';
        *(pDest + 1) = '\0';
        return;
    }

    if (numero < 0) {
        esNegativo = true;
        numero = -numero;
    }

    char temp[20];
    char *pTemp = temp;

    while (numero > 0) {
        *pTemp = (numero % 10) + '0';
        pTemp++;
        numero /= 10;
    }

    if (esNegativo) {
        *pDest = '-';
        pDest++;
    }

    while (pTemp > temp) {
        pTemp--;
        *pDest = *pTemp;
        pDest++;
    }
    *pDest = '\0';
}

// Problema 7
void eliminarRepetidos(const char *origen, char *destino) {
    const char *pOrig = origen;
    char *pDest = destino;

    while (*pOrig != '\0') {
        bool repetido = false;
        for (const char *pCheck = destino; pCheck < pDest; pCheck++) {
            if (*pCheck == *pOrig) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            *pDest = *pOrig;
            pDest++;
        }
        pOrig++;
    }
    *pDest = '\0';
}

// Problema 9
int sumarGrupos(const char *cadena, int n) {
    const char *pLen = cadena;
    while (*pLen != '\0') {
        pLen++;
    }
    int longitud = pLen - cadena;

    int residuo = longitud % n;
    int cerosFaltantes = (residuo == 0) ? 0 : (n - residuo);

    int sumaTotal = 0;
    int numeroActual = 0;
    int digitosProcesados = 0;

    for (int i = 0; i < cerosFaltantes; i++) {
        numeroActual = numeroActual * 10;
        digitosProcesados++;
    }

    const char *p = cadena;
    while (*p != '\0') {
        numeroActual = numeroActual * 10 + (*p - '0');
        digitosProcesados++;

        if (digitosProcesados == n) {
            sumaTotal += numeroActual;
            numeroActual = 0;
            digitosProcesados = 0;
        }
        p++;
    }

    return sumaTotal;
}

// Problema 11: Sala de 15 filas (A-O) y 20 asientos (1-20)
// '+' significa reservado y '-' significa disponible
void mostrarSala(char (*sala)[20], int filas, int cols) {
    // Imprime encabezado de columnas del 1 al 20
    cout << "    ";
    for (int j = 0; j < cols; j++) {
        if (j + 1 < 10) cout << " " << (j + 1) << " ";
        else cout << (j + 1) << " ";
    }
    cout << endl;

    // Recorre cada fila usando aritmetica de punteros sobre filas
    for (int i = 0; i < filas; i++) {
        char letraFila = 'A' + i;
        cout << " " << letraFila << "  ";
        for (int j = 0; j < cols; j++) {
            // *(*(sala + i) + j) accede al asiento en fila i, columna j
            cout << " " << *(*(sala + i) + j) << " ";
        }
        cout << endl;
    }
}

bool gestionarReserva(char (*sala)[20], int filas, int cols, char filaLetra, int asientoNum, bool reservar) {
    // Convierte letra minuscula a mayuscula si es necesario
    if (filaLetra >= 'a' && filaLetra <= 'z') {
        filaLetra = filaLetra - 'a' + 'A';
    }

    int idxFila = filaLetra - 'A';
    int idxCol = asientoNum - 1;

    // Valida que la fila y el asiento esten dentro de los rangos permitidos
    if (idxFila < 0 || idxFila >= filas || idxCol < 0 || idxCol >= cols) {
        return false;
    }

    char *asiento = *(sala + idxFila) + idxCol;

    if (reservar) {
        // Solo reserva si esta disponible ('-')
        if (*asiento == '-') {
            *asiento = '+';
            return true;
        }
        return false;
    } else {
        // Solo cancela si esta reservado ('+')
        if (*asiento == '+') {
            *asiento = '-';
            return true;
        }
        return false;
    }
}

// Problema 13: Cuenta estrellas recibiendo un puntero a enteros
// Ignora los bordes (filas 0 y filas-1, columnas 0 y cols-1)
// Condicion: (centro + izq + der + arriba + abajo) / 5.0 > 6.0
int contarEstrellas(const int *imagen, int filas, int cols) {
    // Si la matriz es muy pequena para tener interior, retorna 0
    if (filas < 3 || cols < 3) {
        return 0;
    }

    int estrellas = 0;

    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            // Desplazamiento lineal en memoria: fila * cols + col
            int centro = *(imagen + i * cols + j);
            int izquierda = *(imagen + i * cols + (j - 1));
            int derecha = *(imagen + i * cols + (j + 1));
            int arriba = *(imagen + (i - 1) * cols + j);
            int abajo = *(imagen + (i + 1) * cols + j);

            double promedio = (centro + izquierda + derecha + arriba + abajo) / 5.0;
            if (promedio > 6.0) {
                estrellas++;
            }
        }
    }

    return estrellas;
}

// Problema 15: Interseccion de rectangulos representados como {x, y, ancho, alto}
void intersectarRectangulos(const int *rectA, const int *rectB, int *rectC) {
    // Extrae datos de A usando punteros
    int ax1 = *(rectA + 0);
    int ay1 = *(rectA + 1);
    int ax2 = ax1 + *(rectA + 2);
    int ay2 = ay1 + *(rectA + 3);

    // Extrae datos de B usando punteros
    int bx1 = *(rectB + 0);
    int by1 = *(rectB + 1);
    int bx2 = bx1 + *(rectB + 2);
    int by2 = by1 + *(rectB + 3);

    // Esquina superior izquierda de la interseccion
    int cx1 = (ax1 > bx1) ? ax1 : bx1;
    int cy1 = (ay1 > by1) ? ay1 : by1;

    // Esquina inferior derecha de la interseccion
    int cx2 = (ax2 < bx2) ? ax2 : bx2;
    int cy2 = (ay2 < by2) ? ay2 : by2;

    // Si hay superposicion valida en ambos ejes, calcula ancho y alto
    if (cx2 > cx1 && cy2 > cy1) {
        *(rectC + 0) = cx1;
        *(rectC + 1) = cy1;
        *(rectC + 2) = cx2 - cx1;
        *(rectC + 3) = cy2 - cy1;
    } else {
        // Si no se intersectan, devuelve ceros
        *(rectC + 0) = 0;
        *(rectC + 1) = 0;
        *(rectC + 2) = 0;
        *(rectC + 3) = 0;
    }
}

// Problema 17: Suma de divisores propios de un numero (excluyendo el mismo numero)
int sumaDivisoresPropios(int num) {
    if (num <= 1) return 0;
    int suma = 1; // 1 siempre es divisor propio para num > 1
    for (int d = 2; d * d <= num; d++) {
        if (num % d == 0) {
            suma += d;
            int pareja = num / d;
            if (pareja != d) {
                suma += pareja;
            }
        }
    }
    return suma;
}

// Suma todos los numeros amigables estrictamente menores que 'limite'
int sumaAmigablesMenores(int limite) {
    int total = 0;
    for (int a = 2; a < limite; a++) {
        int b = sumaDivisoresPropios(a);
        // Deben ser distintos (a != b), b debe ser amigable con a, y estar dentro del limite
        if (b != a && b > 0 && b < limite && sumaDivisoresPropios(b) == a) {
            total += a;
        }
    }
    return total;
}