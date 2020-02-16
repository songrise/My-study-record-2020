import stack


def stockUp(stock):
    up = len(stock)*[0]
    count = len(stock)*[0]
    aStack = stack.Stack()
    up[0] = 1
    aStack.push(0)

    for k in range(1, len(stock)):
        # counting for the first iteration
        count[k] += 2
        # pop until the top is greater
        while not aStack.isEmpty() and stock[aStack.peek()] <= stock[k]:
            aStack.pop()
            # counting for the next and subsequent iteration
            if aStack.isEmpty():
                count[k] += 1
            else:
                count[k] += 2
        # This is for the comparison below

        count[k] += 1
        if aStack.isEmpty():  # greater than all others days before
            up[k] = k+1
        else:
            up[k] = k - aStack.peek()
        aStack.push(k)

    return up, count


stockPrice = [7, 12, 9, 6, 3, 9, 10, 11, 12]
#stockPrice = [7, 12, 9, 6, 3, 9, 10]
#stockPrice = [12,10,9,9,7,6,3]
#stockPrice = [3,6,7,9,9,10,12]
result, countCompare = stockUp(stockPrice)
totalCountCompare = 0
print("{0:>6}{1:>6}{2:>6}{3:>15}".format(
    "Day", "Price", "Up", "# comparisons"))
for i in range(len(stockPrice)):
    print("{0:>6d}{1:>6d}{2:>6d}{3:>15d}".format(
        i+1, stockPrice[i], result[i], countCompare[i]))
    totalCountCompare += countCompare[i]

print("The total number of comparisons is", str(totalCountCompare)+'.')
