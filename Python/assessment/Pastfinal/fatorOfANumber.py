# write in 2020/1/17 13mins


def getNum() -> int:
    """get and return a positive integer"""
    try:
        n = int(input("Please input a positive number:"))
    except:
        print("you must input a positive integer!")
        eixt(1)
    if n <= 0:
        print("the number sholud larger than 0!")
        exit(1)

    return n


def findFactor(num: int) -> list:
    """
    Brute-force algorithm to find the factor
    Input: a number
    OutPut: a list containing all factors of the number
    """
    factor = []
    for i in range(1, num+1):
        if num % i == 0:
            factor.append(i)
    return factor


def main():
    num = getNum()
    fac = findFactor(num)
    print("the factors for {} are{}".format(num, fac))


main()
