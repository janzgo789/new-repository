#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k;
    int n = mat->r;

    // Glowna petla eliminacji - idziemy po kolumnach (krokach)
    for (k = 0; k < n - 1; k++) {
        
        // Sprawdzamy, czy element na diagonali nie jest zerem
        // Jesli jest, nie mozemy dzielic (dla uproszczenia zwracamy blad)
        if (mat->data[k][k] == 0.0) {
            return 1; 
        }

        // Petla po wierszach ponizej diagonali (k)
        for (i = k + 1; i < n; i++) {
            
            // Wspolczynnik do zerowania elementu mat[i][k]
            double q = mat->data[i][k] / mat->data[k][k];

            // Odejmujemy wiersz k pomnozony przez q od wiersza i
            for (j = k; j < n; j++) {
                mat->data[i][j] -= q * mat->data[k][j];
            }

            // To samo robimy dla wektora wynikow b
            b->data[i][0] -= q * b->data[k][0];
        }
    }

    return 0;
}