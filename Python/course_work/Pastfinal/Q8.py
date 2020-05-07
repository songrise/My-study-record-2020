def getrow() -> int:
    try:
        row = int(input("Enter number of rows:"))
    except:  # error handling
        print("Invalid  input")
        exit(-1)
    if row < 0:
        print("invalid input")
        exit(-1)
    return row


def gen(row: int):
    """Generrante a Floyd's triangel"""
    before_newline = [(n*n+n)/2 for n in range(1, row+1)]
    # using // rather than / to avoid a cast. however truncate will never happen.
    for i in range(1, ((row*row+row)//2)+1):
        print("{} ".format(i), end='')
        if i in before_newline:
            print('')  # print an implicate '\n'


def genReversed(row: int):
        """Generrante a reversed Floyd's triangel"""
    before_newline = [((n*n-n)/2)+1 for n in range(1, row+1)]
    # using // rather than / to avoid a cast. however truncate will never happen.
    for i in range(((row*row+row)//2), 0, -1):
        print("{} ".format(i), end='')
        if i in before_newline:
            print('')


def genSum(row: int) -> int:
    """return the sum of odd lines"""
    maxNum = (row*row+row)//2
    sum = (1+maxNum)*maxNum//2
    return sum


def main():
    row = getrow()
    gen(row)
    genReversed(row)
    print("The sum of integes in odd row(s)", genSum(row))


main()
