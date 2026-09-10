#include "mi_libreria.h"

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