def factorial(n):
    # Input: n, a non-negative integer
    # Output: return n!
    mulTimes = 0
    if n == 0:
        return 1, 0
    else:
        result = 1
        for i in range(1, n+1):
            result = result * i
            mulTimes += 1
    return result, mulTimes


for i in range(20):
    # *unpact a list(which is impcately returnned by the func)
    print("{:<2}! ={:<22}, no.multi = {}".format(i, *factorial(i)))
