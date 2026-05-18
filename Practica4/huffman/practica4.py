from heapq import *
from collections import Counter


# ==========================
# NODO
# ==========================

class Nodo:

    def __init__(self, freq, letra=None, izq=None, der=None):

        self.freq = freq
        self.letra = letra
        self.izq = izq
        self.der = der

    def __lt__(self, other):
        return self.freq < other.freq


# ==========================
# GENERAR CODIGOS
# ==========================

def generar(nodo, codigo, tabla):

    if nodo is None:
        return

    # hoja
    if nodo.letra is not None:

        tabla[nodo.letra] = codigo
        return

    generar(nodo.izq, codigo + "0", tabla)
    generar(nodo.der, codigo + "1", tabla)


# ==========================
# DECODIFICAR
# ==========================

def decodificar(bits, raiz):

    texto = ""
    actual = raiz

    for b in bits:

        if b == "0":
            actual = actual.izq
        else:
            actual = actual.der

        # hoja
        if actual.letra is not None:

            texto += actual.letra
            actual = raiz

    return texto


# ==========================
# MAIN
# ==========================

# leer archivo
with open("archTex.txt", "r", encoding="utf-8") as f:
    texto = f.read()

print("\nTexto original:\n")
print(texto)


# frecuencias
freq = Counter(texto)

print("\nFrecuencias:\n")
for c, f in freq.items():
    if c == "\n":
        print("\\n ->", f)
    else:
        print(c, "->", f)


# heap
heap = [Nodo(f, c) for c, f in freq.items()]
heapify(heap)


# construir árbol
while len(heap) > 1:

    a = heappop(heap)
    b = heappop(heap)

    nuevo = Nodo(
        a.freq + b.freq,
        None,
        a,
        b
    )

    heappush(heap, nuevo)


raiz = heap[0]


# tabla de códigos
tabla = {}
generar(raiz, "", tabla)

print("\nCodigos Huffman:\n")
for c, code in tabla.items():
    if c == "\n":
        print("\\n ->", code)
    else:
        print(c, "->", code)


# codificar
bits = "".join(tabla[c] for c in texto)

print("\nTexto codificado:\n")
print(bits)


# decodificar
decodificado = decodificar(bits, raiz)

print("\nTexto decodificado:\n")
print(decodificado)


# verificar
if texto == decodificado:
    print("\nDecodificacion correcta")
else:
    print("\nError en la decodificacion")