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

// Problema 11: Reservas de asientos en sala de cine (15 filas x 20 asientos)
void mostrarSala(char (*sala)[20], int filas, int cols);
bool gestionarReserva(char (*sala)[20], int filas, int cols, char filaLetra, int asientoNum, bool reservar);

// Problema 13: Conteo de estrellas usando puntero a enteros
int contarEstrellas(const int *imagen, int filas, int cols);

// Problema 15: Interseccion entre dos rectangulos A y B -> C
void intersectarRectangulos(const int *rectA, const int *rectB, int *rectC);

// Problema 17: Suma de numeros amigables menores que un limite
int sumaDivisoresPropios(int num);
int sumaAmigablesMenores(int limite);

#endif