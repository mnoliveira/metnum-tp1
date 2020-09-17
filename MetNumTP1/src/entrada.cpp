//
// Created by Matias on 9/16/2020.
//

#include "fstream"
#include "entrada.h"

Entrada cargarEntrada(string path) {

    Entrada entrada;

    ifstream archivo;
    archivo.open(path);

    if (!archivo.is_open()){
        printf("Archivo invalido\n");
        return entrada;
    }

    archivo >> entrada.cantidadEquipos >> entrada.cantidadPartidos;
    Matriz matriz(entrada.cantidadPartidos, vector<double>(5));

    int i = 0, j = 0;
    while (!archivo.eof()){

        archivo >> matriz[i][j];

        j++;
        if (j % 5 == 0){
            i++;
            j = 0;
        }
    }

    entrada.matriz = matriz;

    return entrada;
}