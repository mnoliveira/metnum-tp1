
#include "common.h"
#include "cmm.h"
#include "wp.h"
#include "goles.h"

vector<double> promedio(Entrada entrada) {

    vector<double> rankingCMM = cmm(entrada);
    vector<double> rankingWP = wp(entrada);
    vector<double> rankingGoles = goles(entrada);

    vector<double> res(entrada.cantidadEquipos, 0);

    for (int i = 0; i < res.size(); ++i) {
        res[i] = (rankingCMM[i] + rankingWP[i] + rankingGoles[i])/3;
    }

    return res;
}