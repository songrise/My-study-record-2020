import stack


def lessOrEqu(fir: str, sec: str) -> bool:
    """return true if first operand is (less or equal) than second in term of priority"""
    if fir == '-' or fir == '+':
        if sec == '/' or sec == '*'or sec == '-'or sec == '+':
            return True
    else:
        return False


def itp(expr: str):
    s = stack.Stack()
    i = 0
    ans = []
    for i in range(len(expr)):
        symbol = expr[i]

        if symbol.isdigit():
            ans.append(symbol)

        else:  # is an operand
            if symbol == ')':
                while s.peek() != '(':
                    ans.append(s.pop())
                s.pop()
            else:
                if s.hasItem():
                    if lessOrEqu(symbol, s.peek()):
                        while s.hasItem() and lessOrEqu(symbol, s.peek()) and s.peek() != '(':
                            # pop until empty or find an operand of less priority
                            ans.append(s.pop())
                s.push(symbol)

    while s.hasItem():
        ans.append(s.pop())

    return ans


print("".join(itp('2+4*3+(8*7+9)*5')))
