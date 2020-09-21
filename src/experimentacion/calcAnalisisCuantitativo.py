from general import *

tests = ["test_completo_10_1", "test_completo_100_4", "test_completo_100_8", "test_completo_1000_2", "test_completo_1000_8"]

df = pd.DataFrame(data={}, columns=["test", "metodo", "diferencia"])

i=0
for test in tests:
    colley =  np.array(tprun("0", f"../tests/test_completos/{test}.in", f"../tests/test_completos/{test}.out"), dtype=float)
    wp = np.array(tprun("1", f"../tests/test_completos/{test}.in", f"../tests/test_completos/{test}.out"), dtype=float)
    expected = np.array(getRankings(f"../tests/test_completos/{test}.expected"), dtype=float)
    colley = np.subtract(colley, expected)
    wp = np.subtract(wp, expected)
    
    for val in wp:
        df.loc[i] = [test, "wp", val]
        i+=1
    for val in colley:
        df.loc[i] = [test, "colley", val]
        i+=1

with open("analisisCuantitativo.pkl", 'wb') as f:
    pickle.dump(df, f)


