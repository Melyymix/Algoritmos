#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaBinaria(int arr[], int n, int clave) {
    int inicio = 0, fin = n - 1;

    while(inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if(arr[medio] == clave)
            return medio;
        else if(arr[medio] < clave)
            inicio = medio + 1;
        else
            fin = medio - 1;
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
    busquedaBinaria(arr, n, clave);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %.10f segundos\n", tiempo);
    printf("Memoria usada aprox: %.2f KB\n", (n * sizeof(int)) / 1024.0);

    free(arr);
    return 0;
}