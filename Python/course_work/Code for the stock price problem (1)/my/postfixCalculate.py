import stack


def postCal(expr: str) -> int:
    """calculate a post-fix expression. error handling is omitted"""
    s = stack.Stack()  # instanlize
    i = 0
    for i in range(len(expr)):
        symbol = expr[i]
        if symbol.isdigit():
            s.push(symbol)
        else:  # is a operator
            first = s.pop()
            second = s.pop()
            ans = str(eval(first+symbol+second))
            s.push(ans)

    return s.peek()


# Suppose all post-fix expression are correct
print(postCal("54+3*2+"))
print(postCal("6523+8*+3+*"))
