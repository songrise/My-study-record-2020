import stack


def parChecker(symbolString):
    s = stack.Stack()
    balanced = True
    index = 0
    while index < len(symbolString) and balanced:
        symbol = symbolString[index]
        if symbol == "(" or symbol == '[' or symbol == '{':
            s.push(symbol)
        else:
            if s.isEmpty():
                balanced = False
            else:
                top = s.pop()
                if top == '[' and symbol != ']':
                    balanced = False
                elif top == '(' and symbol != ')':
                    balanced = False
                elif top == '{' and symbol != '}':
                    balanced = False

        index += 1

    if balanced and s.isEmpty():
        return True
    else:
        return False


print(parChecker('((()))'))
print(parChecker('(()'))
print(parChecker('{[]()}'))
print(parChecker('{[(]))}'))
