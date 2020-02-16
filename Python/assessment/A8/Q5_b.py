import matplotlib.pyplot as plt
import numpy as np

def stockUp(priceFile):

    # read the file
    infile = open(priceFile, "r")
    date = []
    stock = []

    # store only the dates and closing price
    day = 1
    firstLine = True
    for line in infile:
        if firstLine:
            firstLine = False
        else:
            count_item = 0
            for item in line.split(","):
                if count_item == 0:
                    date.append(day)
                elif count_item == 4:
                    stock.append(float(item))
                count_item += 1
        day += 1

    infile.close()

    # Compute the up periods
    up = len(date)*[0]
    for k in range(1,len(stock)):  # skip the heading
        i = k                      # i = k = 1
        while ((i>0) and float(stock[k])>=float(stock[i])):
            up[k] += 1
            i -= 1


    fig, ax1 = plt.subplots()

    color = 'tab:red'
    ax1.set_xlabel('Days started from 11/13/2017 and end on 11/12/2018')
    ax1.set_ylabel('Stock prices', color=color)
    ax1.plot(date, stock, color=color)
    ax1.tick_params(axis='y', labelcolor=color)

    ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

    color = 'tab:blue'
    ax2.set_ylabel('Spans', color=color)
    #ax2.set_ylabel('Up periods', color=color)  # we already handled the x-label with ax1
    ax2.plot(date, up, color=color)
    ax2.tick_params(axis='y', labelcolor=color)

    fig.tight_layout()  # otherwise the right y-label is slightly clipped
    plt.show()

    return

"""
    plt.plot(date, up, marker='x')
    plt.plot(date, stock, marker='o')
    plt.title('The up periods for 11/13/2017-11/12/2018')
    plt.xlabel('Days started from 11/13/2017 and end on 11/12/2018')
    plt.ylabel('The up periods of GOOGL at closing')
    plt.show()
"""            


stockUp("GOOGL.csv")

