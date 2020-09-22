# metnum-tp1

## Compilar

```
g++ ./src/codigo_tp/src/*.cpp ./src/codigo_tp/main.cpp -o src/tp
```

## Ejecutar

```
./src/tp [inputPath] [outputPath] [metodo]
```

- `inputPath` path del archivo de donde extraer los datos
- `outputPath` path donde guardar el archivo resultante

### Metodos

| Parámetro | Método |
| - | - |
| 0 | CMM |
| 1 | WP |
| 2 | Goles |
| 3 | Promedio |

#### Ejemplo de ejecución una vez compilado

```
./tp ./test/test.in ./test/test1.out 0
OJO, desde metnum-tp1 tuve que acceder a src y ademas test.in no existe.
./src/tp src/tests/test1.in src/tests/test1.out 0
```

# Scripts

### compilar con script provisto por la catedra

Primero nos paramos en /src

```
cd src
```

compilamos

```
python metnum.py build
```

### Ejecutar test provistos por la catedra

Parado en la carpeta src

Ejecutamos los test

```
python metnum.py test
```

# Experimentaciones

Para la ejecucion de las experimentaciones se requerira tener instaladas las siguientes librerias:
- Numpy
- matplotlib
- pandas
- pickle
- Jupyter Notebook (jupyterlabs)

### Ejecutar experimento
Posicionarse en la carpeta de experimentacion.
```
cd src/experimentacion
```

Al correr el script del experimento deseado se abrira un grafico mostrando los resultados del experimento.

```
python [experimentoDeseado].py
```

### Experimentos disponibles
| Archivo | Detalle |
| - | - |
| `calcAnalisisCuantitativo.py` | Calculo del Analisis cuantitativo (tarda unos minutos) |
| `cmmJusticia.py` | Grafico para mostrar la "justicia" de CMM |
| `colleyDivergenciaDePartidos.py` | Ranking de Colley con 100 partidas más |
| `comparativa3metodos.py` | Comparacion del ranking de Colley, WP y Goles |
| `equipoHacker.py`  | Resultado de la participacion del equipo Hacker con el metodo de Colley |
| `golesDivergenciaPartidos.py`  | Ranking de Goles con 100 partidas más |
| `promedioDivergenciaDePartidos.py`  | Ranking de Promedio con 100 partidas más |
| `promedioEquipoHacker.py`  | Resultado de la participacion del equipo Hacker con el metodo de Promedio |

### Experimentos rapidos

Se proveen también dos experimentos rápidos hechos en Jupyter Notebook para la visualización clara de los mismos. El documento se llama experimentosRapidos.ipynb y posee dos experimentos:
- Visualización del análisis cuantitativo
- Análisis de los goles de Memphis



