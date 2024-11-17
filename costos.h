#ifndef COSTOS_H
#define COSTOS_H

#include <vector>
#include <string>

using namespace std;

// Declaración de variables globales
extern vector<int> costo_insercion;
extern vector<int> costo_eliminacion;
extern vector<vector<int>> costo_sustitucion;
extern vector<vector<int>> costo_transposicion;

// Declaración de funciones
void cargarCostos(const string& filename, vector<int>& tabla);
void cargarCostosMatriz(const string& filename, vector<vector<int>>& matriz);

int costo_sub(char a, char b);
int costo_ins(char b);
int costo_del(char a);
int costo_trans(char a, char b);

#endif // COSTOS_H
