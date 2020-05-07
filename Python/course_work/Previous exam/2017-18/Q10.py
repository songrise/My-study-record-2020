import sys

def printARange(low, high):
    if low >= high:
          raise ValueError("The low must not be greater than the high.")
    x = low + high
    for i in range(low, high + 1):
        print(str(i), end="")
        if i != high:
            print (", ", end="")
    print()
def main():

    try:
        printARange(1, 10)
    except Exception as e:
        print(e)

    try:
        printARange("x", 10)
    except Exception as e:
        print(e)

    try:
        printARange(1, "y")
    except Exception as e:
        print(e)

    try:
        printARange("a", "b")
    except Exception as e:
        print(e)

    try:
        printARange(5, 5)
    except Exception as e:
        print(e)

    try:
        printARange(6, 7)
    except Exception as e:
        print(e)

main()
