def func(min, max, opr):
    # error handling
    if not (isinstance(min, int) and isinstance(max, int):
        raise TypeError
    if min > max:
        raise ValueError

    if opr == "+":
        return max + min
    elif opr == "-":
        return max - min
    elif opr == "*":
        return max * min
    elif opr == "/":
        if min == 0:
            raise ZeroDivisionError
        else:
            return max / min
    else:
        raise ValueError
