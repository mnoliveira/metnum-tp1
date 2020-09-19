import subprocess as sp
import numpy as np
import random

import pickle

# configuracion de plots
from matplotlib import pyplot as plt
from matplotlib import rc, rcParams, axes
from matplotlib import axes as mplibAxes
import pandas as pd

# class partido:
#     def __init__(self, fecha, iEquipo, iGoles, jEquipo, jGoles):
#         self.fecha = fecha
#         self.iEquipo = iEquipo
#         self.iGoles = iGoles
#         self.jGoles = jGoles
#         self.jEquipo = jEquipo

def tprun(algoritmo, input, output):
    comando = ["../tp", input, output, algoritmo]
    sp.check_call(comando, encoding="utf8")
    
    rankings = []
    with open(output, 'r') as f:
        for line in f:
            [ranking] = [float(x) for x in line.rstrip('\n').split(' ')]
            rankings.append(ranking)
    return rankings
def getNombres(file):
    nombres = []
    with open(file, 'r') as f:
        nombres=[]
        for line in f:
            nombre = line.rstrip('\n')
            nombres.append(nombre)
    return nombres

# for x in range(100):
#     print(1003 + x, 14, np.random.randint(75, 115), 23, np.random.randint(75, 115))


