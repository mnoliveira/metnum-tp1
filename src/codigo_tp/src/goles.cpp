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

    //TODO: Entender si vale la pena y como normalizar este resultado
    
    return res;
}