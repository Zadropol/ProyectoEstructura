#pragma once
#include <iostream>
#include <vector>	
#include <string>

#define INF 1e9
using namespace std;

template <class T>
class Nodo
{

public:
	bool marca;
	string padre;
	int dist;
	vector<pair<int, T>> lista;
	Nodo();
	Nodo(T padre);
	void eliminarAdyacentes(T e);
};

template<class T>
inline Nodo<T>::Nodo()
{
	this->marca = false;
}

template<class T>
inline Nodo<T>::Nodo(T padre)
{
	this->marca = false;
	this->dist = INF;
	this->padre = "";
}

template<class T>
inline void Nodo<T>::eliminarAdyacentes(T e)
{
	int last = lista.size() - 1;

	for (int i = 0; i <= lista.size(); i++) {
		if (lista[i].second == e) {
			swap(lista[i], lista[last]);
			lista.pop_back();
			break;
		}
	}
}
