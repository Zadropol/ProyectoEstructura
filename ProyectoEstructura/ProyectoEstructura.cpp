#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grafo.h"

using namespace std;

int main() {
    srand(time(NULL));
    Grafo<string> g;

    cout << "=== CORTE MINIMO BASICO ===" << endl;

    // 1. Cargar datos
    g.leerArchivo();

    // 2. Ejecutar azar una vez para demostrar
    cout << "\n1. PRUEBA DE AZAR:" << endl;
    string a, b;
    g.azar(a, b);

    // 3. Ejecutar corte mínimo completo
    cout << "\n2. EJECUTANDO CORTE MINIMO:" << endl;
    int resultado = g.MinCut();

    cout << "\n3. RESULTADO: " << resultado << endl;

    return 0;
}