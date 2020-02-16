from math import sin, cos
delX = 0.001


def diff(f):
    global delX, x
    return (f(x+delX)-f(x-delX))/(2*delX)


x = float(input())
print("{:.2f}".format(diff(sin)))
