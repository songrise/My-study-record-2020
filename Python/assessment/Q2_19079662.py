
def getbondary() -> str:
    """get the symble to draw"""
    bon = input("Please enter an symbol for the boundary:")
    return bon


def getinside() -> str:
    """get the symble to draw"""
    sym = input("Please enter an symbol for the inside:")
    return sym


def getnum() -> int:
    """get the width of top bondary ,i is non-negative"""
    i = int(input("please enter the width for the top edge\nin terms of an odd number:"))
    if i <= 0:  # error handling
        print("width should be lager than 0!")
        exit(-1)
    return i


def draw(bon: str, ins: str, wid: int):
    """draw an inverted triangel in the given format"""
    width = wid
    if wid % 2:  # calculate the height
        lines = wid//2+1
    else:
        lines = wid//2

    for i in range(lines):
        if i == 0:
            print("{:^{}}".format(bon*wid, width))
            wid -= 2
            continue
        elif i == lines-1:
            print("{:^{}}".format(bon if wid % 2 else bon*2, width))
        else:
            print("{:^{}}".format(bon+ins*(wid-2)+bon, width))
            wid -= 2


def main():
    # driver
    bon = getbondary()
    ins = getinside()
    width = getnum()

    if (width % 2) == 0:
        print("Warning: You entered an even number!")

    draw(bon, ins, width)


main()
