#include "common.h"

vector<double> goles (Entrada &entrada) {
    vector<double> res = vector<double>(entrada.cantidadEquipos, 0);
    for (int k = 0; k < entrada.cantidadPartidos; k++) {
        int equipoI = entrada.partidos[k][iEquipo] - 1;
        int equipoJ = entrada.partidos[k][jEquipo] - 1;
        int golesI = entrada.partidos[k][iGoles];
        int golesJ = entrada.partidos[k][jGoles];

        res[equipoI] += (golesI - golesJ);
        res[equipoJ] += (golesJ - golesI);
    }

    // normalizacion de la data en el rango 0 a 1
    // Mediante la cuenta x_i = x_i - min(x) / (max(x) - min(x))
    double max = max_element(res);
    double min = min_element(res);
    for(int k = 0; k < res.size(); k++) {
        res[k] = (res[k] - min) / (max - min);
    }

    return res;
}