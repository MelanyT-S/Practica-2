#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

// Problema 1: Descomposición de dinero
void descomponerDinero(int cantidad, const int *denominaciones, int tam, int *cantidades, int *faltante);

// Problema 3: Comparación de dos cadenas
bool compararCadenas(const char *cad1, const char *cad2);

// Problema 5: Conversión de entero a cadena
void enteroACadena(int numero, char *cadena);

// Problema 7: Eliminación de caracteres repetidos
void eliminarRepetidos(const char *origen, char *destino);

// Problema 9: Suma de grupos de N cifras
int sumarGrupos(const char *cadena, int n);

#endif