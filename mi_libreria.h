#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

// Problema 1: Determina la cantidad mínima de billetes y monedas
// Recibe la cantidad ingresada, puntero a las denominaciones (constante),
// puntero al arreglo de cantidades y puntero para el faltante.
void descomponerDinero(int cantidad, const int *denominaciones, int tam, int *cantidades, int *faltante);

#endif