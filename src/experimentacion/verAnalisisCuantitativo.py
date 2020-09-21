from general import *
with open("analisisCuantitativo.pkl", "rb") as f:
    df = pickle.load(f)
df.groupby(by=["test", "metodo"]).mean()