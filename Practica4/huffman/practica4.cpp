#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// ==========================
// NODO
// ==========================

struct Nodo {

    char letra;
    int freq;

    Nodo* izq;
    Nodo* der;
};

// ==========================
// CREAR NODO
// ==========================

Nodo* crearNodo(char letra, int freq) {

    Nodo* n = new Nodo();

    n->letra = letra;
    n->freq = freq;

    n->izq = nullptr;
    n->der = nullptr;

    return n;
}

// ==========================
// COMPARADOR MIN HEAP
// ==========================

struct Comparar {

    bool operator()(Nodo* a, Nodo* b) {

        return a->freq > b->freq;
    }
};

// ==========================
// GENERAR CODIGOS
// ==========================

void generarCodigos( Nodo* raiz, string codigo, map<char, string>& tabla)
{
    if (raiz == nullptr)
        return;

    // hoja
    if (raiz->izq == nullptr &&
        raiz->der == nullptr) {

        tabla[raiz->letra] = codigo;

        return;
    }

    generarCodigos(raiz->izq, codigo + "0", tabla);

    generarCodigos( raiz->der, codigo + "1", tabla);
}

// ==========================
// CODIFICAR
// ==========================

string codificar(string texto, map<char, string>& tabla) {

    string bits = "";

    for (int i = 0; i < texto.size(); i++) {

        bits += tabla[texto[i]];
    }

    return bits;
}

// ==========================
// DECODIFICAR
// ==========================

string decodificar( string bits, Nodo* raiz)
{

    string texto = "";

    Nodo* actual = raiz;

    for (int i = 0; i < bits.size(); i++) {

        if (bits[i] == '0')
            actual = actual->izq;
        else
            actual = actual->der;

        // hoja
        if (actual->izq == nullptr &&
            actual->der == nullptr) {

            texto += actual->letra;

            actual = raiz;
        }
    }

    return texto;
}

// ==========================
// MAIN
// ==========================

int main() {

    ifstream archivo("archTex.txt");

    if (!archivo) {

        cout << "No se pudo abrir el archivo\n";

        return 1;
    }

    // ==========================
    // LEER TEXTO
    // ==========================

    string texto;
    string linea;

    while (getline(archivo, linea)) {

        texto += linea;
        texto += '\n';
    }

    archivo.close();

    if (texto.empty()) {

        cout << "Archivo vacio\n";

        return 1;
    }

    cout << "\nTexto original:\n";

    cout << texto << endl;

    // ==========================
    // FRECUENCIAS
    // ==========================

    map<char, int> freq;

    for (int i = 0; i < texto.size(); i++) {

        freq[texto[i]]++;
    }

    // ==========================
    // PRIORITY QUEUE (MIN HEAP)
    // ==========================

    priority_queue< Nodo*, vector<Nodo*>, Comparar> pq;

    // insertar nodos
    for (auto par : freq) {

        Nodo* n =
            crearNodo(
                par.first,
                par.second
            );

        pq.push(n);
    }

    // ==========================
    // CONSTRUIR HUFFMAN
    // ==========================

    while (pq.size() > 1) {

        // dos menores
        Nodo* a = pq.top();
        pq.pop();

        Nodo* b = pq.top();
        pq.pop();

        // nuevo nodo padre
        Nodo* nuevo =
            crearNodo(
                '$',
                a->freq + b->freq
            );

        nuevo->izq = a;
        nuevo->der = b;

        pq.push(nuevo);
    }

    // raiz final
    Nodo* raiz = pq.top();

    // ==========================
    // TABLA DE CODIGOS
    // ==========================

    map<char, string> tabla;

    generarCodigos(raiz,"",tabla);

    cout << "\nCodigos Huffman:\n";

    for (auto par : tabla) { //for - each

        if (par.first == '\n')
            cout << "\\n";
        else
            cout << par.first;

        cout << " -> " << par.second << endl;
    }

    // ==========================
    // CODIFICAR
    // ==========================

    string bits = codificar(texto,tabla);

    cout << "\nTexto codificado:\n";

    cout << bits << endl;

    // ==========================
    // DECODIFICAR
    // ==========================

    string decodificado = decodificar(bits,raiz);

    cout << "\nTexto decodificado:\n";

    cout << decodificado << endl;

    // ==========================
    // VERIFICAR
    // ==========================

    if (texto == decodificado)
        cout << "\nDecodificacion correcta\n";
    else
        cout << "\nError\n";

    return 0;
}