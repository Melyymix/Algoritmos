#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int busquedaIndexada(const vector<int>& arr, int x) {
    int n = arr.size();
    int k = sqrt(n); // Tamaño del bloque
    int i = 0;

    // Buscar el bloque
    while (i < n && arr[i] <= x) {
        i += k;
    }

    // Búsqueda lineal en el bloque previo
    int inicio = max(0, i - k);
    int fin = min(i, n);
    for (int j = inicio; j < fin; j++) {
        if (arr[j] == x) return j;
    }
    return -1;
}

int main() {
    long n = 1000000;
    vector<int> datos(n);
    for (int i = 0; i < n; i++) datos[i] = i;

    int objetivo = n - 1;

    auto inicio = high_resolution_clock::now();
    int resultado = busquedaIndexada(datos, objetivo);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<microseconds>(fin - inicio);

    cout << "--- BUSQUEDA INDEXADA ---" << endl;
    cout << "Elementos: " << n << endl;
    cout << "Tiempo: " << duracion.count() << " us" << endl;
    cout << "Memoria aprox: " << (sizeof(int) * n) / 1024 << " KB" << endl;

    return 0;
}