#include "costos.h"
#include <iostream>
#include <fstream>

using namespace std;

// Definición de variables globales
vector<int> costo_insercion(26);
vector<int> costo_eliminacion(26);
vector<vector<int>> costo_sustitucion(26, vector<int>(26));
vector<vector<int>> costo_transposicion(26, vector<int>(26));

void cargarCostos(const string& filename, vector<int>& tabla) {
    ifstream archivo(filename);
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            archivo >> tabla[i];
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }
}

void cargarCostosMatriz(const string& filename, vector<vector<int>>& matriz) {
    ifstream archivo(filename);
    if (archivo.is_open()) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                archivo >> matriz[i][j];
            }
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }
}

int costo_sub(char a, char b) {
    a = tolower(a);
    b= tolower(b);
    return costo_sustitucion[a - 'a'][b - 'a'];
}

int costo_ins(char b) {
    b= tolower(b);
    return costo_insercion[b - 'a'];
}

int costo_del(char a) {
    a = tolower(a);
    return costo_eliminacion[a - 'a'];
}

int costo_trans(char a, char b) {
    a = tolower(a);
    b= tolower(b);
    return costo_transposicion[a - 'a'][b - 'a'];
}
