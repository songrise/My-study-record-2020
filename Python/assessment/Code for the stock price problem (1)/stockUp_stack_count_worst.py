import stack
import itertools
import math

def stockUp(stock):
    up = len(stock)*[0]
    aStack = stack.Stack()
    up[0] = 1
    aStack.push(0)

    count_while_nonempty = 0
    for k in range(1,len(stock)):
        # counting for the first iteration
        count_while_nonempty += 2
        while not aStack.isEmpty() and stock[aStack.peek()] <= stock[k]:
            aStack.pop()
            # counting for the next and subsequent iteration
            if aStack.isEmpty():
                None
            else:
                count_while_nonempty += 2
        # This is for the comparison below
        if aStack.isEmpty():
            up[k] = k+1
        else:
            up[k] = k - aStack.peek()
        aStack.push(k)

    return up,count_while_nonempty

def main():
    print("{0:<7}{1:<15}{2:<30}".format("# day","Max # comparisons","Price list")) 
    for days in range(2,13):
        maxCount = 0
        priceList = list(range(days))
        permutatDay = list(itertools.permutations(priceList))
        for stock in permutatDay:
            up, count = stockUp(stock)
            if count > maxCount:
                maxCount = count
                maxStock = stock

        print("{0:<7d}{1:<15d}{2:<30}".format(days,maxCount,str(maxStock)))

main()
