#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class Grafo {
private:
    unordered_map<T, vector<T>> graf;
    vector<T> vertices;

public:
    // Insertar arista
    void InsertarArista(T a, T b) {
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    // LEER ARCHIVO SIMPLIFICADO
    void leerArchivo() {
        cout << "Leyendo archivo..." << endl;

        // Datos fijos de tu archivo
        InsertarArista("LP", "CBBA");
        InsertarArista("LP", "TARIJA");
        InsertarArista("CBBA", "TARIJA");
        InsertarArista("CBBA", "ORURO");
        InsertarArista("ORURO", "PANDO");

        // Llenar vertices
        for (auto& par : graf) {
            vertices.push_back(par.first);
        }

        cout << "Grafo listo! Nodos: ";
        for (auto v : vertices) cout << v << " ";
        cout << endl;
    }

    // FUNCIÓN AZAR - SUPER SIMPLE
    void azar(T& v1, T& v2) {
        // Elegir nodo aleatorio
        int i1 = rand() % vertices.size();
        v1 = vertices[i1];

        // Elegir vecino aleatorio
        int i2 = rand() % graf[v1].size();
        v2 = graf[v1][i2];

        cout << "Azar eligio: " << v1 << " - " << v2 << endl;
    }

    // CONTRAER ARISTA - SIMPLIFICADO
    void ContraerArista(T v1, T v2) {
        cout << "Contrayendo " << v1 << " y " << v2 << endl;

        // Mover todas las conexiones de v2 a v1
        for (auto vecino : graf[v2]) {
            if (vecino != v1) {
                graf[v1].push_back(vecino);
                // Actualizar el vecino para que apunte a v1
                for (auto& v : graf[vecino]) {
                    if (v == v2) v = v1;
                }
            }
        }

        // Eliminar v2
        graf.erase(v2);
        // Actualizar lista de vertices
        vertices.clear();
        for (auto& par : graf) {
            vertices.push_back(par.first);
        }
    }

    // CORTE MÍNIMO - VERSIÓN BÁSICA
    int MinCut() {
        cout << "\n--- INICIANDO CORTE MINIMO ---" << endl;

        while (graf.size() > 2) {
            T v1, v2;
            azar(v1, v2);
            ContraerArista(v1, v2);

            cout << "Nodos restantes: " << graf.size() << endl;
        }

        // El corte son las aristas del primer nodo
        int corte = graf.begin()->second.size();
        cout << "CORTE MINIMO = " << corte << endl;
        return corte;
    }
};