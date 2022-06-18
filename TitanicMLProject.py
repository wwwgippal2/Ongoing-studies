# -*- coding: utf-8 -*-
"""
Created on Fri Jun 17 21:13:26 2022

@author: gugah
"""

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd



data= pd.read_csv(r"C:\Users\gugah\Downloads\titanic\train.csv")
data

columns = data.columns
columns

data.head()

data.describe()

data['Survived'].mean()

data['Embarked']

"Takes part of the dataset in which the survivors are women, then adds the '1's' of the survivors"
"then divides by the total of women. Thus getting the percentage of female survivors"

women = data.loc[data.Sex == 'female']['Survived']
women
rate_women_live = sum(women)/len(women)
rate_women_live 


men = data.loc[data.Sex == 'male']['Survived']
men
rate_men_live = sum(men)/len(men)
rate_men_live 


advantage_female_over_male = rate_women_live/rate_men_live

advantage_female_over_male

"Women are around 4 times more likely to survive the titanic"


"Data analysis on the basis of social standing"
data.Pclass.describe()


p1 = data.loc[data.Pclass == 1]['Survived']
rate_p1_live = sum(p1)/len(p1)
rate_p1_live 

p2 = data.loc[data.Pclass == 2]['Survived']
rate_p2_live = sum(p2)/len(p2)
rate_p2_live 

p3 = data.loc[data.Pclass == 3]['Survived']
rate_p3_live = sum(p3)/len(p3)
rate_p3_live 

"Getting test data"

test_data = pd.read_csv(r"C:\Users\gugah\Downloads\titanic\test.csv")



from sklearn.ensemble import RandomForestClassifier

y = data["Survived"]

features = ["Pclass", "Sex", "SibSp", "Parch"]
X = pd.get_dummies(data[features])
X_test = pd.get_dummies(test_data[features])

model = RandomForestClassifier(n_estimators=100, max_depth=5, random_state=1)
model.fit(X, y)
predictions = model.predict(X_test)

output = pd.DataFrame({'PassengerId': test_data.PassengerId, 'Survived': predictions})
output.to_csv('submission.csv', index=False)
print("Your submission was successfully saved!")
output
