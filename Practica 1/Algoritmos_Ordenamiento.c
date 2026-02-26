#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* ================= FUNCIONES DE ORDENAMIENTO ================= */

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/* Merge Sort */

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* ================= FUNCIONES AUXILIARES ================= */

void llenarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void copiarArreglo(int origen[], int destino[], int n) {
    memcpy(destino, origen, n * sizeof(int));
}

/* ================= MAIN ================= */

int main() {

    srand(time(NULL));

    int tamanos[] = {10, 100, 1000, 10000, 100000, 1000000};
    int numPruebas = 6;

    for(int t = 0; t < numPruebas; t++) {

        int n = tamanos[t];
        printf("\n==============================\n");
        printf("Tamaño del arreglo: %d\n", n);
        printf("==============================\n");

        int *original = (int*)malloc(n * sizeof(int));
        int *copia = (int*)malloc(n * sizeof(int));

        llenarArreglo(original, n);

        double memoriaBase = n * sizeof(int) / 1024.0; // KB

        /* -------- BUBBLE -------- */
        copiarArreglo(original, copia, n);
        clock_t inicio = clock();
        bubbleSort(copia, n);
        clock_t fin = clock();

        double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Bubble Sort:\n");
        printf("Tiempo: %.6f segundos\n", tiempo);
        printf("Memoria usada aprox: %.2f KB\n\n", memoriaBase);

        /* -------- INSERTION -------- */
        copiarArreglo(original, copia, n);
        inicio = clock();
        insertionSort(copia, n);
        fin = clock();

        tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("Insertion Sort:\n");
        printf("Tiempo: %.6f segundos\n", tiempo);
        printf("Memoria usada aprox: %.2f KB\n\n", memoriaBase);

        /* -------- MERGE -------- */
        copiarArreglo(original, copia, n);
        inicio = clock();
        mergeSort(copia, 0, n - 1);
        fin = clock();

        tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

        double memoriaMerge = memoriaBase * 2; // usa arreglos auxiliares

        printf("Merge Sort:\n");
        printf("Tiempo: %.6f segundos\n", tiempo);
        printf("Memoria usada aprox: %.2f KB\n\n", memoriaMerge);

        free(original);
        free(copia);
    }

    return 0;
}