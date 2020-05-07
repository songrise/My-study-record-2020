import stack


def pro(a: int, b: int) -> int:
    return a+b


def main():
    s = stack.Stack()
    n = [4, 6, 9, 13, 21, 14]
    for i in n:
        s.push(i)

    while not s.isEmpty():
        fir = s.pop()
        if not s.isEmpty():
            sec = s.pop()
            sum_ = pro(fir, sec)
            s.push(sum_)
        else:
            print("The sum is ", fir)


main()
