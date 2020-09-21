from general import *

promedioSinDivergencia = tprun("3", "nba_2016.in", "nba_2016.out")
promedio = tprun("3", "nba_2016_divergencia_de_partidos.in", "nba_2016_divergencia_de_partidos.out")
nombres = getNombres("nombres_nba")

def scatterPlot(data, color, label):
    plt.scatter(data, df.index, s=30, alpha=1, label=label, color=color)
    #esto es para agregarle el valor a los puntitos
    # for x, y, tex in zip(data, df.index, data):
    #     t = plt.text(x, y, round(tex, 1), horizontalalignment='center', 
    #                 verticalalignment='center', fontdict={'color':'white'})

# Prepare Data

df = pd.DataFrame(data={
    'nombres': nombres, 
    'promedio': promedio,
    'promedioSinDivergencia': promedioSinDivergencia
})
df.sort_values('promedioSinDivergencia', inplace=True)
df.reset_index(inplace=True)



# Draw plot
plt.figure(figsize=(14,16), dpi= 80)
scatterPlot(df.promedio, 'red', "Jugando 100 partidos extra")
scatterPlot(df.promedioSinDivergencia, 'blue', "Original")


plt.yticks(df.index, df.nombres)
plt.title('Rankings NBA 2016 con divergencia de partidos - Método Promedio', fontdict={'size':20})
plt.xlabel('Ranking')
plt.grid(linestyle='--', alpha=0.5)
plt.xlim(0, 1)
plt.legend()
plt.show()