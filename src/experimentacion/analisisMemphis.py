from general import *
df=pd.DataFrame({}, columns=["fecha", "iEquipo", "iGoles", "jEquipo", "jGoles"])
i=0
with open("nba_2016.in","r") as f:
    for line in f:
        if(i > 1):
            [fecha, iEquipo, iGoles, jEquipo, jGoles] = [int(x) for x in line.rstrip('\n').split(' ')]
            df.loc[i-1] = [fecha, iEquipo, iGoles, jEquipo, jGoles]
        
        i+=1


        
vals = df['jEquipo'] == 15
vals2 = df['iEquipo'] == 15

# memphisLocal = df[vals]
# memphisLocal = memphisLocal[memphisLocal['jGoles'] < memphisLocal['iGoles']]
# memphisLocal

memphisVisitante = pd.DataFrame.copy(df[vals])
memphisVisitante.reset_index(inplace=True)
sumcol = memphisVisitante['iGoles'] - memphisVisitante['jGoles']
memphisVisitante['dif'] = sumcol
memphisVisitante = memphisVisitante[memphisVisitante['dif'] > 0]
memphisVisitante['dif'].mean()
# memphisVisitante
