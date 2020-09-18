#include "common.h"
#include "cmm.h"

void transformarEntradaEnCMM(Entrada &entrada, CMM &res) {
    //Inicializo la matriz en 0
    Matriz C(entrada.cantidadEquipos, vector<double>(entrada.cantidadEquipos, 0));
    res.C = C;
    for (int k = 0; k < entrada.cantidadPartidos; k++) {
        int equipoI = entrada.partidos[k][iEquipo] - 1;
        int equipoJ = entrada.partidos[k][jEquipo] - 1;
        int golesI = entrada.partidos[k][iGoles];
        int golesJ = entrada.partidos[k][jGoles];
        int quienGano = golesI > golesJ ? equipoI : equipoJ;
        int quienPerdio = quienGano == equipoI ? equipoJ : equipoI;

        // i == j
        res.C[equipoI][equipoI] += 1;
        res.C[equipoJ][equipoJ] += 1;

        // i != j
        res.C[equipoI][equipoJ] -= 1;
        res.C[equipoJ][equipoI] -= 1;

        // acumulo en b
        res.b[quienPerdio]--;
        res.b[quienGano]++;
    }
    for(int k = 0; k < entrada.cantidadEquipos; k++) {
        //sumo 2 en toda la diagonal
        res.C[k][k] += 2;
        //sumo 1 y divido por 2 el b
        res.b[k] = 1 + (res.b[k] / 2);
    }
}

vector<double> cmm (Entrada entrada) {
    vector<double> res;
    CMM entradaCmm;
    transformarEntradaEnCMM(entrada, entradaCmm);

    return resolverSistema(entradaCmm.C, entradaCmm.b);
}

void eliminacionGaussiana(Matriz &mat, vector<double> &b) {
    double cociente = 0;
    for (int i = 0; i < mat.size() - 1; ++i) {
        for (int j = i + 1; j < mat.size(); ++j) {
            if (mat[j][i] != 0) {
                cociente = mat[j][i] / mat[i][i];
                for (int k = i; k < mat[j].size(); ++k) {
                    mat[j][k] = mat[j][k] - cociente * mat[i][k];
                }
                b[j] = b[j] - cociente * b[i];
            }
        }
    }
}

vector<double> resolverSistema (Matriz &mat, vector<double> &b) {
    eliminacionGaussiana(mat, b);
    int n = b.size();
    int j;
    vector<double> res(n,0);
    for(int i = n-1; i>=0;i--){
        j = i+1;
        res[i] = b[i];
        while(j<n){
            res[i] -= mat[i][j] * res[j];
            j++;
        }
        res[i] /= mat[i][i];
    }
    return res;
}
