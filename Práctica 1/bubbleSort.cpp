#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>


using namespace std;

void bubbleSort(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int N = 100000;
    int *arr = new int[N];
    srand(time(NULL)); // Semilla para que cambien cada ejecución
    // Leer archivo
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    cout << "Datos cargados. Ordenando...\n";

    auto inicio = chrono::high_resolution_clock::now(); //Para el calculo de tiempo del ordenamiento

    bubbleSort(arr, N);
    
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    std::cout << std::fixed << std::setprecision(10)<< duracion.count() << " segundos\n";
    cout << "Memoria aprox: " << (sizeof(int) * N) / 1024 << " KB" << endl;
    delete[] arr;

    return 0;
}
