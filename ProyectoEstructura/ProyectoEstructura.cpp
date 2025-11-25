#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grafo.h"

using namespace std;

int main() {
    srand(time(NULL));
    Grafo<string> g;

    cout << "=== CORTE MINIMO BASICO ===" << endl;

    g.leerArchivo("Min_Cut_NOMBRES Prueba.txt");

    cout << "\n1. PRUEBA DE AZAR:" << endl;
    string a, b;
    g.azar(a, b);

    cout << "\n2. EJECUTANDO CORTE MINIMO COMPLETO:" << endl;
    int resultado = g.MinCut();

    cout << "\n3. RESULTADO FINAL: " << resultado << endl;

    return 0;
}