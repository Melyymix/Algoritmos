#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

// Función merge
void merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];
}

// Merge Sort
void mergeSort(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main()
{

    const int N = 10000000;

    int *arr = new int[N];
    int *temp = new int[N];

    srand(time(NULL)); // Semilla para que cambien cada ejecución
    
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    cout << "Datos cargados. Ordenando...\n";

    auto inicio = chrono::high_resolution_clock::now(); //Para el calculo de tiempo del ordenamiento

    mergeSort(arr, temp, 0, N - 1);

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    std::cout << std::fixed << std::setprecision(10)<< duracion.count() << " segundos\n";
    cout << "Memoria aprox: " << (2*(sizeof(int) * N)) / 1024 << " KB" << endl;

    delete[] arr;
    delete[] temp;

    return 0;
}