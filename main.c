#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
    // 1. Sprawdzenie czy podano pliki wejsciowe
    if (argc < 3) {
        fprintf(stderr, "Uzycie: %s [plik z macierza A] [plik z wektorem b]\n", argv[0]);
        return 1;
    }

    int res;
    
    // 2. Wczytanie danych
    Matrix * A = readFromFile(argv[1]);
    Matrix * b = readFromFile(argv[2]);

    if (A == NULL) {
        fprintf(stderr, "Blad: Nie udalo sie wczytac macierzy A z pliku %s\n", argv[1]);
        return -1;
    }
    if (b == NULL) {
        fprintf(stderr, "Blad: Nie udalo sie wczytac wektora b z pliku %s\n", argv[2]);
        freeMatrix(A); // Sprzatanie
        return -2;
    }

    // 3. Wyswietlenie danych wejsciowych
    printf("\n--- Dane wejsciowe ---\n");
    printf("Macierz A:\n");
    printToScreen(A);
    printf("Wektor b:\n");
    printToScreen(b);

    // 4. Eliminacja Gaussa
    printf("\n--- Obliczenia ---\n");
    res = eliminate(A, b);

    if (res != 0) {
        fprintf(stderr, "Blad eliminacji Gaussa! Kod bledu: %d (np. macierz osobliwa)\n", res);
    } else {
        // Eliminacja sie udala, robimy podstawienie wsteczne
        Matrix * x = createMatrix(b->r, 1);
        
        if (x != NULL) {
            res = backsubst(x, A, b);

            if (res != 0) {
                fprintf(stderr, "Blad wstecznego podstawienia! Kod bledu: %d (np. 0 na diagonali)\n", res);
            } else {
                // Sukces - wyswietlamy wynik
                printf("\n--- Wynik ---\n");
                printf("Wektor x:\n");
                printToScreen(x);
            }
            freeMatrix(x);
        } else {
            fprintf(stderr, "Blad: Nie udalo sie zaalokowac pamieci na wynik x.\n");
        }
    }

    // 5. Sprzatanie pamieci
    freeMatrix(A);
    freeMatrix(b);

    return 0;
}	