#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busquedaBinaria(const vector<int>& arr, int x) {
    int bajo = 0, alto = arr.size() - 1;
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (arr[medio] == x) return medio;
        if (arr[medio] < x) bajo = medio + 1;
        else alto = medio - 1;
    }
    return -1;
}

int main() {
    long n = 10000000; // 10 Millones
    vector<int> datos(n);
    for (int i = 0; i < n; i++) datos[i] = i;

    int objetivo = n - 1;

    auto inicio = high_resolution_clock::now();
    int resultado = busquedaBinaria(datos, objetivo);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<microseconds>(fin - inicio);

    cout << "--- BUSQUEDA BINARIA ---" << endl;
    cout << "Elementos: " << n << endl;
    cout << "Tiempo: " << duracion.count() << " us" << endl;
    cout << "Memoria aprox: " << (sizeof(int) * n) / 1024 << " KB" << endl;

    return 0;
}