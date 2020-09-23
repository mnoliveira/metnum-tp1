import subprocess as sp
import numpy as np
import random

# configuracion de plots
from matplotlib import pyplot as plt
from matplotlib import rc, rcParams, axes
from matplotlib import axes as mplibAxes
import pandas as pd
import platform

import pickle

# class partido:
#     def __init__(self, fecha, iEquipo, iGoles, jEquipo, jGoles):
#         self.fecha = fecha
#         self.iEquipo = iEquipo
#         self.iGoles = iGoles
#         self.jGoles = jGoles
#         self.jEquipo = jEquipo

def tprun(algoritmo, input, output):
    ejecutable = "../tp"
    system = platform.system()
    if system == "Windows":
        ejecutable = "../tp.exe"
    comando = [ejecutable, input, output, algoritmo]
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

def getRankings(file):
    rankings = []
    with open(file, 'r') as f:
        rankings=[]
        for line in f:
            ranking = float(line.rstrip('\n'))
            rankings.append(ranking)
    return rankings


# for i in range(90):
#     print(f"{1003 + i} 10 {np.random.randint(100, 130)} 23 {np.random.randint(70, 99)}")

# for i in range(10):
#     print(f"{1093 + i} 10 {np.random.randint(70, 99)} 23 {np.random.randint(100, 130)}")

