#include "./main.h"


int main(int argc, char *argv[]) {
    string inputPath;
    string outputPath;
    int metodo;
    
    if (argc < 4) {
        printf("Faltan parametros de entrada.");
        return 0;
    } else {
        inputPath = argv[1];
        outputPath = argv[2];
        metodo = atoi(argv[3]);
    }

    Entrada entrada = cargarEntrada(inputPath);

    if (metodo > 3) {
        printf("Metodo inválido");
        return 1;
    }

    vector<double> r; // ranking

    // eleccion de metodo:
    switch (metodo) {
        case 0:
            r = cmm(entrada);
            break;
        case 1:
            r = wp(entrada);
            break;
        case 2:
            r = goles(entrada);
            break;
        case 3:
            r = promedio(entrada);
            break;
    }

    ofstream outputFile;
    outputFile.open(outputPath);

    write_vector(r, outputFile);
    outputFile.close();

    return 0;
}

void write_vector (vector<double> &v, ofstream &output){
    for (int i = 0; i < v.size(); i++){
        output << v[i] << "\n";
    }
}
