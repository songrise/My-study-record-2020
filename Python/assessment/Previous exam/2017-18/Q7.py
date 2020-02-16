from graphics import *

def main():

    inFile = open("votes.txt", "r")
    inputV = inFile.read()
    listV = inputV.split()
    count = [0, 0, 0]
    for i in listV:
        count[ord(i)-65] = count[ord(i)-65] + 1
    win = GraphWin("Election Result", 320, 400)
    win.setCoords(0, -400, 8, 4400)
    win.setBackground("white")

    Line(Point(1, 0), Point(7, 0)).draw(win)

    Text(Point(2, -200), 'A').draw(win)
    Text(Point(4, -200), 'B').draw(win)
    Text(Point(6, -200), 'C').draw(win)

    xll = 1
    barWidth = 2
    for candidate in range(1, 4):
        xll = (candidate - 0.5) * barWidth
        bar = Rectangle(Point(xll, 0), Point(xll + barWidth, count[candidate - 1] * 330))
        bar.setFill("green")
        bar.setWidth(2)
        bar.draw(win)

main()
