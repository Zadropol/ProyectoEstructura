#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class Grafo {
private:
    unordered_map<T, vector<T>> graf;
    vector<T> vertices;

public:
    void leerArchivo(string nombreArchivo);
    void azar(T& v1, T& v2);
    void ContraerArista(T v1, T v2);
    int MinCut();
};

template<class T>
inline void Grafo<T>::leerArchivo(string nombreArchivo)
{
    cout << "Leyendo archivo: " << nombreArchivo << endl;

    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string origen, destino;

        ss >> origen;

        while (ss >> destino && destino != "-1") {
            graf[origen].push_back(destino);
            graf[destino].push_back(origen);
            cout << "Arista: " << origen << " - " << destino << endl;
        }
    }
    archivo.close();

    for (auto& par : graf) {
        vertices.push_back(par.first);
    }

    cout << "Archivo leido! Nodos: ";
    for (auto v : vertices) cout << v << " ";
    cout << endl;
}

template<class T>
inline void Grafo<T>::azar(T& v1, T& v2)
{

    int i1 = rand() % vertices.size();
    v1 = vertices[i1];

    int i2 = rand() % graf[v1].size();
    v2 = graf[v1][i2];

    cout << "Azar eligio: " << v1 << " - " << v2 << endl;
}

template<class T>
inline void Grafo<T>::ContraerArista(T v1, T v2)
{
    cout << "Contrayendo " << v1 << " y " << v2 << endl;

    for (auto vecino : graf[v2]) {
        if (vecino != v1) {
            graf[v1].push_back(vecino);
            for (auto& v : graf[vecino]) {
                if (v == v2) v = v1;
            }
        }
    }

    graf.erase(v2);
    vertices.clear();
    for (auto& par : graf) {
        vertices.push_back(par.first);
    }
}

template<class T>
inline int Grafo<T>::MinCut()
{
    cout << "\n--- INICIANDO CORTE MINIMO ---" << endl;

    while (graf.size() > 2) {
        T v1, v2;
        azar(v1, v2);
        ContraerArista(v1, v2);
        cout << "Nodos restantes: " << graf.size() << endl;
    }

    int corte = graf.begin()->second.size();
    cout << "CORTE MINIMO = " << corte << endl;
    return corte;
}
