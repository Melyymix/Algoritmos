#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int max_cruce(int A[], int izq, int mid, int der)
{
    int suma = 0;
    int izq_max = INT_MIN;

    for (int i = mid; i >= izq; i--)
    {
        suma += A[i];
        izq_max = max(izq_max, suma);
    }

    suma = 0;
    int der_max = INT_MIN;

    for (int i = mid + 1; i <= der; i++)
    {
        suma += A[i];
        der_max = max(der_max, suma);
    }

    return izq_max + der_max;
}

int maxSubArray(int A[], int izq, int der)
{
    if (izq == der)
        return A[izq];

    int mid = (izq + der) / 2;

    int izquierda = maxSubArray(A, izq, mid);
    int derecha = maxSubArray(A, mid + 1, der);
    int cruce = max_cruce(A, izq, mid, der);

    return max({izquierda, derecha, cruce});
}

int main()
{
    const int N = 10;
    int *A = new int[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        A[i] = -100 + rand() % 201;
    }

    int resultado = maxSubArray(A, 0, N - 1);

    cout << "La suma maxima es: " << resultado << endl;

    return 0;
}