#include "common.h"

vector<double> wp (Entrada entrada) {

    const int INDICE_GANADOS = 0;
    const int INDICE_PERDIDOS = 1;

    vector<double> res(entrada.cantidadEquipos);
    Matriz resultados(entrada.cantidadEquipos, vector<double>(2));

    for (int i = 0; i < entrada.partidos.size(); ++i) {
        int equipoI = entrada.partidos[i][iEquipo] - 1;
        int equipoJ = entrada.partidos[i][jEquipo] - 1;
        int golesI = entrada.partidos[i][iGoles];
        int golesJ = entrada.partidos[i][jGoles];
        int quienGano = golesI > golesJ ? equipoI : equipoJ;
        int quienPerdio = quienGano == equipoI ? equipoJ : equipoI;

        resultados[quienGano][INDICE_GANADOS]++;
        resultados[quienPerdio][INDICE_PERDIDOS]++;
    }

    for (int i = 0; i < resultados.size(); ++i) {
        res[i] = resultados[i][INDICE_GANADOS] / (resultados[i][INDICE_GANADOS] + resultados[i][INDICE_PERDIDOS]);
    }

    return res;
}