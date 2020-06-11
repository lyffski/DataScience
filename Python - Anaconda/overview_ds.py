

import pandas as pd

df = pd.read_txt("ds_name.{ext}", delimiter="\t") #delimiter split by parameter
print(df.head(3)) #first 3 
print(df.tail(3)) #last 3
df[["Name", "type1", "HP"]] #print the list of parameters, already in order
df.iloc[0:4, 2] #iloc==iterationLocation  # 5 col and of 2 var → specified numeric
df.loc[df["type1"] == "Grass"] #display all "type1" that have "grass"

for index, row in df.iterrows(): #iterate through each row
  print(index, row["Name"]) #specified the name without it print whole var in all col

df.sort_values(["type1", "HP"], ascending = [1,0]) #1st ascending 2rd descending

df["Att&Def"] = df["Attact"] + df["Defence"] #adding you col to set named "Att&Def"

dr = df.dro(columns=["Total"]) #drop col

df["Total"] = df.iloc[:, 4:10].sum(axis=1) #add all rows ":" and add "4:10" 4th till 9th col because we dot not the 10 col //axis=1 → add horizontally || axis=0 add vertically

cols = list(df.columns.valuse) #list all cols into one var
df = df[cols[0:4] + [cols[-1]] + cols[4:12]]

df.to_csv("modifed.csv", index=False) #create "modifed.csv" file without additional index
df.to_csv("modifed.txt", index=False, sep="\t") #sep → seperated by tab<

df.loc[(df["type1"] == "Grass") & (df.loc["type2"]=="poison")] #can have multiply condition

new_df = df.reset.reset_index(drop=True, inplace==Ture) #inplace replace the index || drop=True drop the old index

df.loc[~df["name"].str.contains("Mega")] #select||delete(~) all var that contains str "Mega" in "name" col 
import re
df.loc[df["type1"].str.contains("Fire|Grass",flags=re.I, regex=True)] #regex can be used "flag=re.I" → ignore CAsEsEnSetive

df.loc[df["type1"] == "Fire", "type1"] = "Flamer"  #change where type1 == Fire to type1 == Flamer instead of Fire 
df.loc[df["Total"] > 500, ["Generation","Legendary"]] = ["insteadOfGenerationValue","insteadOfLegendaryValuse"] #where Total > 500 change the "Generation" and "Legendary" valuse to "TestValuse"


#Aggregate Statsistics (GroupBy)

df["count"] = 1 #ensure that no erorrs will blowup
df.groupby(["Type1"]).count().sort_values("Defence", ascending=False) #group type1 by count then sort by highest "Defence"
dg.groupby(["Type1", "Type2"]).count()["count"] #count all rightly, but prove this vers one more time before you use it ok?

pd.read_csv("modifed.csv", chunksize=5): #to not load whole data for example do not load 40gb for once

 

