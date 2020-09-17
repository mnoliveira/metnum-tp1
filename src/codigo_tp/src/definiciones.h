//
// Created by Matias on 9/16/2020.
//

#ifndef METNUMTP1_DEFINICIONES_H
#define METNUMTP1_DEFINICIONES_H

#include <vector>
#include <map>

using namespace std;

enum IndiceMatrizEntrada { fecha = 0, iEquipo = 1, iGoles = 2, jEquipo = 3, jGoles = 4};
typedef vector<vector<double>> Matriz;
typedef vector<vector<int>> Partidos;
struct Entrada{
    int cantidadEquipos;
    int cantidadPartidos;
    Partidos partidos;
};

struct CMM{
    Matriz C;
    vector<double> b;
    vector<double> r;
};

#endif //METNUMTP1_DEFINICIONES_H
