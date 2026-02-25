#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void insertionSort(int *arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = clave;
    }
}

int main()
{

    int N = 100000;
    int *arr = new int[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    cout << "Datos cargados. Ordenando...\n";

    auto inicio = chrono::steady_clock::now(); //Para el calculo de tiempo del ordenamiento

    insertionSort(arr, N);

    auto fin = chrono::steady_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    std::cout << std::fixed << std::setprecision(10)<< duracion.count() << " segundos\n";
   cout << "Memoria aprox: " << (sizeof(int) * N) / 1024 << " KB" << endl;
    delete[] arr;

    return 0;
}