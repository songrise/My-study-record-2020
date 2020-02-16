import stack

def stockUp(stock):
    up = len(stock)*[0]
    aStack = stack.Stack()
    up[0] = 1
    aStack.push(0)
    
    for k in range(1,len(stock)):
        while not aStack.isEmpty() and stock[aStack.peek()] <= stock[k]:
            aStack.pop()
        if aStack.isEmpty():
            up[k] = k+1
        else:
            up[k] = k - aStack.peek()
        aStack.push(k)
        
    return up


stockPrice = [7, 12, 9, 6, 3, 9, 10]
print(stockUp(stockPrice))

