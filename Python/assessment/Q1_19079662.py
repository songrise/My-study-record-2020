
def getsym() -> str:
    """get the symble to draw"""
    sym = input("Please enter an symbol for the boundary:")
    return sym


def getnum() -> int:
    i = int(input("please enter the width for the top edge\nin terms of an odd number:"))
    if i <= 0:  # error handling
        print("width should be lager than 0!")
        exit(-1)
    return i


def draw(sym: str, wid: int):
    width = wid
    if wid % 2:  # calculate the height
        lines = wid//2+1
    else:
        lines = wid//2

    for i in range(lines):
        print("{:^{}}".format(sym*wid, width))
        wid -= 2


def main():
    symbol = getsym()
    width = getnum()

    if (width % 2) == 0:
        print("Warning: You entered an even number!")

    draw(symbol, width)


main()
