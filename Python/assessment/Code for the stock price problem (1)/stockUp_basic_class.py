def stockUp(stock):
    """
    Input: stock is a list of stock prices on a range of days which starts from day 0.
    Output: a list of up-periods for the days.
    """
    # initialization
    up = len(stock)*[1]
    
    # for each day
    for k in range(1,len(stock)):
        i = k-1
        # go backward one day at a time
        # stop when the previous day has a higher price
        while i>=0 and stock[k]>=stock[i]:
            up[k] = up[k]+1
            i -= 1
            
    return up

# testing
stockPrice = [7, 12, 9, 6, 3, 9, 10]
result = stockUp(stockPrice)
for i in range(len(stockPrice)):
    print("Day ", i+1,": ", result[i])
