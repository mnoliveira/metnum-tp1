# metnum-tp1

## Compilar

```
g++ ./src/codigo_tp/src/*.cpp ./src/codigo_tp/main.cpp -o tp
```

## Ejecutar

```
./tp [inputPath] [outputPath] [metodo]
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
./tp ./test/test.in ./test/test1.out
```

# Scripts

### Ejecutar test provistos por la catedra

Primero nos paramos en /src

```
cd src
```

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
| `calcAnalisisCuantitativo.py` | Analisis cuantitativo |
| `cmmJusticia.py` | Grafico para mostrar la "justicia" de CMM |
| `colleyDivergenciaDePartidos.py` | Ranking de Colley con 100 partidas más |
| `comparativa3metodos.py` | Comparacion del ranking de Colley, WP y Goles |
| `equipoHacker.py`  | Resultado de la participacion del equipo Hacker con el metodo de Colley |
| `golesDivergenciaPartidos.py`  | Ranking de Goles con 100 partidas más |
| `promedioDivergenciaDePartidos.py`  | Ranking de Promedio con 100 partidas más |
| `promedioEquipoHacker.py`  | Resultado de la participacion del equipo Hacker con el metodo de Promedio |

### Análisis cuantitativo

Posicionado en la carpeta de experimentacion los siguientes comandos en orden:

Para calcular los resultados
```
python calcAnalisisCuantitativo.py
```
Para ver los resultados
```
python verAnalisisCuantitativo.py
```


