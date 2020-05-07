from graphics import *
import math

width = 500
height = 500

length = 500

win = GraphWin("Line Art", height, width)

for i in range (0, 15):

    space = length/14.0
    
    l = Line(Point(0, 0), Point(width - space * i, space * i))
    l.draw(win)


