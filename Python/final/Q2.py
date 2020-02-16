import stack


def daySaving(stock: list) -> list:
    """
    A function to return the number of days skipped by the stack-based algorithm
    when computing the up period for each day
    Input: A list of stock prices
    Output: A list of the number of days skipped by the stack-based algorithm
    """
    save = [0 for i in range(len(stock))]
    s = stack.Stack()
    # first two day cannot save. they are treated as special case
    for i in range(len(stock)):  # i is day
        if s.isEmpty():
            s.push(i)
        else:
            k = i-1
            com = 0
            while (not s.isEmpty()) and k >= 0 and (stock[i] >= stock[k]):
                com += 1
                s.pop()
                k -= 1
            save[i] = (i-k - 1) - com

        s.push(i)
    save[1] = 0

    for i in range(s.size()):
        print(s.pop())

    return save


    # test
stock = [7, 12, 9, 6, 3, 9, 10]
print(daySaving(stock))
# stock = [12, 10, 9, 9, 7, 6, 3]
# print(daySaving(stock))
# stock = [3, 6, 7, 9, 9, 10, 12]
# print(daySaving(stock))
# stock = [7, 12, 9, 6, 3, 9, 10, 11, 13]
# print(daySaving(stock))
