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
struct Entrada{
    int cantidadEquipos;
    int cantidadPartidos;
    Matriz matriz;
};

struct CMM{
    Matriz C;
    vector<double> B;
    vector<double> r;
};

#endif //METNUMTP1_DEFINICIONES_H
