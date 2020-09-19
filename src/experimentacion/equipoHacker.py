from general import *

def obtenerOrden(df, metodo): 
    df.sort_values(metodo, inplace=True)
    df.reset_index(inplace=True)
    df.columns = ["ordenOriginal", metodo, "nombres"]
    df.sort_values("ordenOriginal", inplace=True)

nombres = getNombres("nombres_nba_equipoHacker")

colley = tprun("0", "nba_2016_equipoHacker.in", "nba_2016_equipoHacker.out")
colleyDf = pd.DataFrame(data={'colley': colley, 'nombres': (x for x in range(len(nombres)))})
obtenerOrden(colleyDf, "colley")

wp = tprun("1", "nba_2016_equipoHacker.in", "nba_2016_equipoHacker.out")
wpDf = pd.DataFrame(data={'wp': wp, 'nombres': (x for x in range(len(nombres)))})
obtenerOrden(wpDf, "wp")

goles = tprun("2", "nba_2016_equipoHacker.in", "nba_2016_equipoHacker.out")
golesDf = pd.DataFrame(data={'goles': goles, 'nombres': (x for x in range(len(nombres)))})
obtenerOrden(golesDf, "goles")

# Prepare Data

df = pd.DataFrame(data={
    'nombres': nombres, 
    'colley': colleyDf.index + 1,
    'wp': wpDf.index + 1,
    'goles': golesDf.index + 1
})
df.sort_values('colley', inplace=True)
df.reset_index(inplace=True)

x = np.arange(len(df.nombres))  # the label locations
width = 0.2  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x + width, df.colley, width, label='Colley', color="blue")
rects2 = ax.bar(x, df.wp, width, label='WP', color="red")
rects3 = ax.bar(x - width, df.goles, width, label='GOLES', color="green")

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Puesto')
ax.set_title('NBA 2016 con equipo Hacker')
ax.set_yticks(range(1, 32,1))
ax.set_yticklabels(str(x) for x in range(31, 0,-1))
ax.set_xticks(x)
ax.set_xticklabels(df.nombres, rotation=45, ha="right")
ax.legend()

plt.grid(axis="y", linestyle='--', alpha=0.5)
plt.show()
