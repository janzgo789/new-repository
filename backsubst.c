#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Sprawdzenie poprawnosci rozmiarow macierzy
    if (mat->r != mat->c || mat->r != b->r || mat->r != x->r) {
        return 2;
    }

    int i, j;
    int n = mat->r;

    // Petla idaca od ostatniego rownania do pierwszego
    for (i = n - 1; i >= 0; i--) {
        if (mat->data[i][i] == 0.0) {
            return 1; // Element na diagonali to 0
        }

        double sum = 0.0;
        // Odejmujemy wyrazy znane (z prawej strony diagonali)
        for (j = i + 1; j < n; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }

        // Wyliczenie niewiadomej x[i]
        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }

    return 0;
}