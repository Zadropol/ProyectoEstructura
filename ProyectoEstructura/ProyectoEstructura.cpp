#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grafo.h"

using namespace std;

int main() {
    srand(time(NULL));
    Grafo<string> g;


    g.leerArchivo("Min_Cut_NOMBRES Prueba.txt");

    int aux = 100;
	int tam = g.getVertices().size();
    for (int i = 0; i <tam; i++)
    {
        Grafo<string> copia = g;        // copia del grafo original
        int corte = copia.MinCut();     // ejecuta Karger
        cout << "Ejecución " << i + 1 << " corte = " << corte << endl;
        if (corte < aux) aux = corte;
    }

    cout << "Nuevo corte minimo encontrado: " << aux << endl;

    return 0;
}