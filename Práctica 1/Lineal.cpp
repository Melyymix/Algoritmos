#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busquedaLineal(const vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    // Prueba con: 10, 100, 1000, 10000, 100000, 1000000, 10000000
    long n = 1000000; 
    vector<int> datos(n);
    for (int i = 0; i < n; i++) datos[i] = i;

    int objetivo = n - 1; // Peor caso (el último elemento)

    auto inicio = high_resolution_clock::now();
    int resultado = busquedaLineal(datos, objetivo);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<microseconds>(fin - inicio);

    cout << "--- BUSQUEDA LINEAL ---" << endl;
    cout << "Elementos: " << n << endl;
    cout << "Tiempo: " << duracion.count() << " us" << endl;
    cout << "Memoria aprox: " << (sizeof(int) * n) / 1024 << " KB" << endl;

    return 0;
}