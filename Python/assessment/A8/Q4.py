def factorial(n):
    if n == 0:
        return 1
    else:
        result = 1
        for i in range(1,n+1):
            result = result * i
        return result

def factorial_count(n):
    if n == 0:
        return 1,0
    else:
        result = 1
        for i in range(1,n+1):
            result = result * i
        return result, n

def addFactorial(n):
    sum = 0
    for i in range(n+1):
        sum += factorial(n)

    return sum

def addFactorial_count(n):
    totalSum = 0
    totalCount = 0
    for i in range(n+1):
        sum, count = factorial_count(i)
        totalSum += sum
        totalCount += count

    return totalSum, totalCount

def addFactorial_count_fast(n):
    if n == 0:
        return 1,0
    else:
        count = 0
        fact = 1
        sum = 1
        for i in range(1,n+1):
            fact *= i
            sum += fact
            count += 1
        return sum, count


for n in range(20):
    fact1, count1 = factorial_count(n)
    fact2, count2 = addFactorial_count(n)
    print("{0:<3} = {1:<20} no. multi. = {3:<5} sum of {0:<3} = {2:<20} no. multi. = {4:<5}".format(str(n)+"!",fact1,fact2,count1,count2))

print()

for n in range(20):
    fact1, count1 = addFactorial_count(n)
    fact2, count2 = addFactorial_count_fast(n)
    print("{0:<4} the old addFactorial: {1:<20} {3:<6} the new addFactorial: {2:<20} {4:<6}".format(str(n)+"!:",fact1,fact2,count1,count2))
    
