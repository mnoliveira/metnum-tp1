from general import *

def obtenerOrden(df, metodo): 
    df.sort_values(metodo, inplace=True)
    df.reset_index(inplace=True)
    df.columns = ["ordenOriginal", metodo, "nombres"]
    df.sort_values("ordenOriginal", inplace=True)

nombres = getNombres("justicia_nombres")

antes = tprun("0", "justicia.in", "justicia.out")
antesDf = pd.DataFrame(data={'antes': antes, 'nombres': (x for x in range(len(nombres)))})
obtenerOrden(antesDf, "antes")

despues = tprun("0", "justicia2.in", "justicia2.out")
despuesDf = pd.DataFrame(data={'despues': despues, 'nombres': (x for x in range(len(nombres)))})
obtenerOrden(despuesDf, "despues")

# Prepare Data

df = pd.DataFrame(data={
    'nombres': nombres, 
    'antes': antesDf.index + 1,
    'despues': despuesDf.index + 1
})
df.sort_values('antes', inplace=True)
df.reset_index(inplace=True)

x = np.arange(len(df.nombres))  # the label locations
width = 0.2  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x + width, df.antes, width, label='Original', color="blue")
rects2 = ax.bar(x, df.despues, width, label='Alterado', color="red")

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Puesto')
ax.set_title('¿Es CMM "justo"?')
ax.set_yticks(range(1, 9,1))
ax.set_yticklabels(str(x) for x in range(8, 0,-1))
ax.set_xticks(x)
ax.set_xticklabels(df.nombres, rotation=45, ha="right")
ax.legend()

plt.grid(axis="y", linestyle='--', alpha=0.5)
plt.show()