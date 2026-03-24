#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaLineal(int arr[], int n, int clave) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == clave)
            return i;
    }
    return -1;
}

int main() {
    int n;
    printf("Tamano del arreglo: ");
    scanf("%d", &n);

    int arr = (int)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        arr[i] = i;

    int clave = n - 1;

    clock_t inicio = clock();
    busquedaLineal(arr, n, clave);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %.10f segundos\n", tiempo);
    printf("Memoria usada aprox: %.2f KB\n", (n * sizeof(int)) / 1024.0);

    free(arr);
    return 0;
}