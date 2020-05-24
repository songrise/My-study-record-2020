def removeNonDigit(a):
    return [elem for elem in a if elem.isdigit()]


print(removeNonDigit(["a", "1", "c", "3"]))
