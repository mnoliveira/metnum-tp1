#include <iostream>
#include "src/entrada.h"
#include "src/definiciones.h"

using namespace std;

int main(int argc, char *argv[]) {

    string inputPath;
    string outputPath;
    string metodo;

    //Por ahora para probar
    if (argc < 4){
        printf("Faltan parametros de entrada.");
        return 0;
    } else {
        inputPath = argv[1];
        outputPath = argv[2];
        metodo = argv[3];
    }

    Entrada entrada = cargarEntrada(inputPath);

    return 0;
}
