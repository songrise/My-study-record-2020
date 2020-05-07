# 2020/1/7 14min
def plot(sym: str, width: int):
    height = int((width+1) / 2 if width % 2 else width/2)

    for i in range(height):
        print("{:<{}}".format(sym*(i+1), width//2), end='')
        if (width % 2) and (i == height-1):
            print("{:>{}}".format(sym*(i), width-(width//2)-1, end=''))
        else:
            print("{:>{}}".format(sym*(i+1), width-(width//2), end=''))


def main():
    sym = input("Please enter a symbol:")
    width = int(input("Please enter the width, a positive integer: "))

    plot(sym, width)


main()
