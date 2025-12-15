# Eliminacja Gaussa

Program w jezyku C rozwiazujacy uklady rownan liniowych metoda eliminacji Gaussa z wstecznym podstawieniem.

## Kompilacja

    gcc main.c mat_io.c gauss.c backsubst.c -o gauss

## Uruchomienie

    ./gauss plik_A.txt plik_b.txt

## Format danych

Pliki wejsciowe musza byc plikami tekstowymi:
1. Pierwsza linia: liczba wierszy i liczba kolumn (oddzielone spacja).
2. Kolejne linie: wartosci elementow macierzy.

## Kody bledow

* 0 - Sukces
* 1 - Macierz osobliwa (dzielenie przez 0)
* 2 - Nieprawidlowe wymiary macierzy
