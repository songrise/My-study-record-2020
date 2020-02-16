def sum(l: list):
    length = len(l)
    first_number = l[0]
    if length == 1:
        return first_number
    else:
        l = l[-1:0:-1]
        return first_number + sum(l)


theList = [1, 2, 3, 423, 23, 41, 43]
# successfully recurred.
print(sum(theList))
