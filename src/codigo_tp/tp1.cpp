#include "tp1.h"

using namespace std;

int main (int argc, char *argv[]) {
  //TODO: Condicion de parametros invalidos
  if (false) {
    printf("Parametros inválidos.\n");
    return 0;
  }

  // parametros por linea de comando
  uint modo = atoi(argv[1]);
  string archivoDeEntrada = argv[2];
  string archivoDeSalida = argv[3];

  if (modo > 3) {
    printf("Modo inválido");
    return 1;
  }

  // lectura del input
  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open()) {
    printf("Archivo de entrada invalido.\n");
    return 1;
  }


  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  inputFile >> T >> P;

  vector<double> r; // ranking

  // eleccion de metodo:
  switch (mode) {
    case 0:
      r = cmm(T, P, inputFile);
      break;
    case 1:
      r = wp(T, P, inputFile);
      break;
    case 2:
      r = ahp(T, P, inputFile);
      break;
    case 3:
      r = pseudo_odi(T, P, inputFile);
      break;
    case 4:
      r = cmm(T, P, inputFile, true);
      break;
    case 5:
      r = matriz_rala(T,P, inputFile);
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);#include "tp1.h"

using namespace std;

int main (int argc, char *argv[]) {
  if (argc != 4) {
    printf("Formato de parametros invalido.\n");
    return 1;
  }

  // parametros por linea de comando
  uint mode = atoi(argv[1]);
  char *input = argv[2];
  char *output = argv[3];

  if (mode > 5) {
    printf("Metodo invalido");
    return 1;
  }

  // lectura del input
  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open()) {
    printf("Archivo de entrada invalido.\n");
    return 1;
  }


  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  inputFile >> T >> P;

  vector<double> r; // ranking

  // eleccion de metodo:
  switch (mode) {
    case 0:
      r = cmm(T, P, inputFile);
      break;
    case 1:
      r = wp(T, P, inputFile);
      break;
    case 2:
      r = ahp(T, P, inputFile);
      break;
    case 3:
      r = pseudo_odi(T, P, inputFile);
      break;
    case 4:
      r = cmm(T, P, inputFile, true);
      break;
    case 5:
      r = matriz_rala(T,P, inputFile);
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);

  write_vector(r, outputFile);

  outputFile.close();

  return 0;
}

  write_vector(r, outputFile);

  outputFile.close();

  return 0;
}
  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  inputFile >> T >> P;

  vector<double> r; // ranking

  // eleccion de metodo:
  switch (mode) {
    case 0:
      r = cmm(T, P, inputFile);
      break;
    case 1:
      r = wp(T, P, inputFile);
      break;
    case 2:
      r = goles(T, P, inputFile);
      break;
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);

  write_vector(r, outputFile);

  outputFile.close();

  return 0;
}