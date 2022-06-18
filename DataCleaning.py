# -*- coding: utf-8 -*-
"""
Created on Fri Jun 17 22:33:06 2022

@author: gugah
"""

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd



df= pd.read_csv(r"C:\Users\gugah\Downloads\BL-Flickr-Images-Book.csv")
df

columns = df.columns
columns

pd.isna(df)

to_drop = ['Edition Statement',
           'Corporate Author',
          'Corporate Contributors',
          'Former owner',
          'Engraver',
          'Contributors',
          'Issuance type',
           'Shelfmarks']

df.drop(to_drop, inplace=True, axis=1)

df.columns


df['Identifier'].is_unique "Checks if said column useful as an index"
df = df.set_index('Identifier') "Sets as index"
df.head()
df.loc[206] "loc lists the dataset starting from the defined index"


df.loc[1905:, 'Date of Publication'] "lists with loc but only shows the specified variable"

extr = df['Date of Publication'].str.extract(r'^(\d{4})', expand=False)
extr

pd.isna(extr)

df['Date of Publication'] = pd.to_numeric(extr)
df['Date of Publication'].dtype

df['Date of Publication'].isnull().sum() / len(df) "Checks how many within the dataset are null"


pub = df['Place of Publication']
london = pub.str.contains('London')
london[:5]
oxford = pub.str.contains('Oxford')

df['Place of Publication'] = np.where(london, 'London',
                                      np.where(oxford, 'Oxford',
                                               pub.str.replace('-', ' ')))

df['Place of Publication'].head()
df['Place of Publication'].describe()
df['Place of Publication']

