#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// función auxiliar para obtener el máximo de dos números
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// función que calcula la máxima suma que cruza el punto medio
int max_cruce(int A[], int izq, int mid, int der)
{
    int suma = 0;
    int izq_max = INT_MIN;

    // recorrer hacia la izquierda desde el medio
    for (int i = mid; i >= izq; i--)
    {
        suma += A[i];
        if (suma > izq_max)
            izq_max = suma;
    }

    suma = 0;
    int der_max = INT_MIN;

    // recorrer hacia la derecha desde mid+1
    for (int i = mid + 1; i <= der; i++)
    {
        suma += A[i];
        if (suma > der_max)
            der_max = suma;
    }

    return izq_max + der_max;
}

// función principal recursiva (Divide & Conquer)
int maxSubArray(int A[], int izq, int der)
{
    // caso base
    if (izq == der)
        return A[izq];

    int mid = (izq + der) / 2;

    // resolver subproblemas
    int izquierda = maxSubArray(A, izq, mid);
    int derecha = maxSubArray(A, mid + 1, der);
    int cruce = max_cruce(A, izq, mid, der);

    // regresar el máximo de los tres
    return max(max(izquierda, derecha), cruce);
}

// función main para probar
int main()
{
    const int N = 10;

    int A[N];

    srand(time(NULL)); // Semilla para que cambien cada ejecución

    for (int i = 0; i < N; i++)
    {
        A[i] = -100 + rand() % (100 - -(100) + 1);
    }

    int n = sizeof(A) / sizeof(A[0]);

    int resultado = maxSubArray(A, 0, n - 1);

    printf("La suma maxima del subarreglo es: %d\n", resultado);

    return 0;
}