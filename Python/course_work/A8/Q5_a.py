import matplotlib.pyplot as plt
import csv

x=[]
y=[]

csvfile = open('GOOGL.csv', 'r')
plots= csv.reader(csvfile, delimiter=',')
print(plots)
firstLine = True
day = 1
for row in plots:
    if (firstLine):
        firstLine = False
    else:
        x.append(day)
        y.append(float(row[4]))
        day += 1

plt.plot(x,y, marker='x')
plt.title('Stock price of GOOGL at closing for 11/13/2017-11/12/2018')
plt.xlabel('Days started from 11/13/2017 and end on 11/12/2018')
plt.ylabel('Stock price of GOOGL at closing')
plt.show()
