from graphics import *
import random

def main():
    radius = 50
    winWidth = 1000
    winHeight = 300
    win = GraphWin("Racing Circles", winWidth, winHeight)
    
    # draw the red car
    redY = 70
    redCarC = Point(radius, redY)
    redCar = Circle(redCarC, radius)
    redCar.setFill('red')
    redCar.draw(win)

    # draw the green car
    greenY = 200
    greenCarC = Point(radius, greenY)
    greenCar = Circle(greenCarC, radius)
    greenCar.setFill('green')
    greenCar.draw(win)

    # draw the hurdles
    hWidth = 30
    r1 = random.randint(radius + 100, winWidth - 200)
    r2 = random.randint(radius + 100, winWidth - 200)

    h1 = Rectangle(Point(r1, redY - 50), Point(r1 + 30, redY + 50))
    h1.setFill("yellow")
    h1.draw(win)

    h2 = Rectangle(Point(r2, greenY - 50), Point(r2 + 30, greenY + 50))
    h2.setFill("yellow")
    h2.draw(win)
    

    # print the message
    message = Text(Point(winWidth / 2, winHeight - 20), "Click to Race!")
    message.draw(win)

    # Accept the mouse click
    win.getMouse()
    message.undraw()
    countR = 0
    countG = 0
    while ((redCar.getCenter().getX() + radius < winWidth) and (greenCar.getCenter().getX() + radius < winWidth)):
        if((r1 <= redCar.getCenter().getX() + radius and redCar.getCenter().getX() + radius <= r1 + 30 and countR < 10000)):
            countR = countR + 1
        else:
            redCar.move(random.randint(0, 4), 0)

        if((r2 <= greenCar.getCenter().getX() + radius and greenCar.getCenter().getX() + radius <= r2 + 30 and countG < 10000)):
            countG = countG + 1
        else:
            greenCar.move(random.randint(0, 4), 0)

    result = ""
    if(redCar.getCenter().getX() + radius > greenCar.getCenter().getX() + radius):
        result = "Red wins!"        
    elif(redCar.getCenter().getX() + radius < greenCar.getCenter().getX() + radius):
        result = "Green wins!"
    else:
        result = "Draw!"
        
    message = Text(Point(winWidth / 2, winHeight - 20), result)
    message.draw(win)
main()
