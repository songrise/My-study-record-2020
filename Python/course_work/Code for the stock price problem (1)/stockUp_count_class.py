def stockUp(stock):
    """
    Input: stock is a list of stock prices on a range of days which starts from day 0.
    Output:
    - a list of up-periods for the days.
    - a list of counts of comparisons for the days
    """
    up = len(stock)*[1]
    count = len(stock)*[0]
    # for day 2, day 3, ...
    for k in range(1,len(stock)):
        i = k-1
        # for the first while()
        count[k] += 2
        while i>=0 and stock[k]>=stock[i]:
            up[k] = up[k]+1
            i -= 1
            # for the second and subsequent while()
            if i < 0:
                count[k] += 1
            else:
                count[k] += 2
                
    return up,count

stockPrice = [7, 12, 9, 6, 3, 9, 10, 11, 12]
#stockPrice = [7, 12, 9, 6, 3, 9, 10]
result,countCompare = stockUp(stockPrice)
totalCountCompare = 0
print("{0:>6}{1:>6}{2:>6}{3:>15}".format("Day","Price","Up","# comparisons"))
for i in range(len(stockPrice)):
    print("{0:>6d}{1:>6d}{2:>6d}{3:>15d}".format(i+1,stockPrice[i],result[i],countCompare[i]))
    totalCountCompare += countCompare[i]
    
print("The total number of comparisons is", str(totalCountCompare)+'.')
