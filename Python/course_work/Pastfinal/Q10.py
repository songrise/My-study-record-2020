def printARange(low, high):
    for i in range(low, high+1):
        print(str(i), end='')
        if i != high:
            print(", ", end='')


def main():
    try:
    printARange(1, 10)
    printARange("x", 10)
    printARange(1, "y")
    printARange("a", "b")
    printARange(6, 5)
