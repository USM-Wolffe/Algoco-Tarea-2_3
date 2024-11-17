#include <bits/stdc++.h>
#include<chrono>
#include "costos.h" // Incluye las funciones de costos y carga de datos

using namespace std;

// Algoritmo de distancia de edición usando backtracking con costos dinámicos y transposición
int editDistanceBacktracking(const string &s1, const string &s2, int m, int n) {
    if (m == 0) {
        int costo_total = 0;
        for (int i = 0; i < n; ++i) {
            costo_total += costo_ins(s2[i]);
        }
        return costo_total;
    }

    if (n == 0) {
        int costo_total = 0;
        for (int i = 0; i < m; ++i) {
            costo_total += costo_del(s1[i]);
        }
        return costo_total;
    }

    if (s1[m - 1] == s2[n - 1]) {
        return editDistanceBacktracking(s1, s2, m - 1, n - 1);
    }

    int costo_min = min({
        costo_ins(s2[n - 1]) + editDistanceBacktracking(s1, s2, m, n - 1),        // Insertar
        costo_del(s1[m - 1]) + editDistanceBacktracking(s1, s2, m - 1, n),        // Eliminar
        costo_sub(s1[m - 1], s2[n - 1]) + editDistanceBacktracking(s1, s2, m - 1, n - 1) // Reemplazar
    });

    // Transposición si los caracteres adyacentes se pueden intercambiar
    if (m > 1 && n > 1 && s1[m - 1] == s2[n - 2] && s1[m - 2] == s2[n - 1]) {
        costo_min = min(costo_min, costo_trans(s1[m - 1], s1[m - 2]) + editDistanceBacktracking(s1, s2, m - 2, n - 2));
    }

    return costo_min;
}

// Algoritmo de distancia de edición usando programación dinámica con memoización, costos dinámicos y transposición
int editDistanceMemo(const string &s1, const string &s2, int m, int n, vector<vector<int>> &memo) {
    if (m == 0) {
        int costo_total = 0;
        for (int i = 0; i < n; ++i) {
            costo_total += costo_ins(s2[i]);
        }
        return costo_total;
    }

    if (n == 0) {
        int costo_total = 0;
        for (int i = 0; i < m; ++i) {
            costo_total += costo_del(s1[i]);
        }
        return costo_total;
    }

    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (s1[m - 1] == s2[n - 1]) {
        memo[m][n] = editDistanceMemo(s1, s2, m - 1, n - 1, memo);
    } else {
        memo[m][n] = min({
            costo_ins(s2[n - 1]) + editDistanceMemo(s1, s2, m, n - 1, memo),           // Insertar
            costo_del(s1[m - 1]) + editDistanceMemo(s1, s2, m - 1, n, memo),           // Eliminar
            costo_sub(s1[m - 1], s2[n - 1]) + editDistanceMemo(s1, s2, m - 1, n - 1, memo) // Reemplazar
        });

        // Transposición si los caracteres adyacentes se pueden intercambiar
        if (m > 1 && n > 1 && s1[m - 1] == s2[n - 2] && s1[m - 2] == s2[n - 1]) {
            memo[m][n] = min(memo[m][n], costo_trans(s1[m - 1], s1[m - 2]) + editDistanceMemo(s1, s2, m - 2, n - 2, memo));
        }
    }

    return memo[m][n];
}

int main() {
    // Cadenas de prueba (puedes cambiarlas manualmente)
    string s1 = "igmf";
    string s2 = "yeun";
    int m = s1.length();
    int n = s2.length();

    // Cargar los costos dinámicos desde archivos
    cargarCostos("data/cost_insert.txt", costo_insercion);
    cargarCostos("data/cost_delete.txt", costo_eliminacion);
    cargarCostosMatriz("data/cost_replace.txt", costo_sustitucion);
    cargarCostosMatriz("data/cost_transpose.txt", costo_transposicion);

    // Abrir archivo para guardar resultados
    ofstream resultados("resultados-T.txt", ios::app); // Modo "append" para no sobrescribir
    if (!resultados.is_open()) {
        cerr << "Error al abrir el archivo de resultados." << endl;
        return 1;
    }

    // Medición de tiempo para el algoritmo de fuerza bruta
    auto start = chrono::high_resolution_clock::now();
    int resultadoFB = editDistanceBacktracking(s1, s2, m, n);
    auto end = chrono::high_resolution_clock::now();
    auto tiempoFB = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Fuerza Bruta - Resultado: " << resultadoFB << ", Tiempo: " << tiempoFB << " us" << endl;

    // Guardar resultados en archivo
    resultados << "Fuerza Bruta - s1: " << s1 << ", s2: " << s2 
               << ", Resultado: " << resultadoFB 
               << ", Tiempo: " << tiempoFB << " us" << endl;

    // Medición de tiempo para el algoritmo de programación dinámica
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    start = chrono::high_resolution_clock::now();
    int resultadoPD = editDistanceMemo(s1, s2, m, n, memo);
    end = chrono::high_resolution_clock::now();
    auto tiempoPD = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Programación Dinámica - Resultado: " << resultadoPD << ", Tiempo: " << tiempoPD << " us" << endl;

    // Guardar resultados en archivo
    resultados << "Programación Dinámica - s1: " << s1 << ", s2: " << s2 
               << ", Resultado: " << resultadoPD 
               << ", Tiempo: " << tiempoPD << " us" << endl;

    // Cerrar archivo
    resultados.close();

    return 0;
}



