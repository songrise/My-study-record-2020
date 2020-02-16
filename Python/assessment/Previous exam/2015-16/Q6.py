class Illegal(Exception):
    pass

def getNumber():
    """This function asks user for a positive integer. It will raise Illegal for any illegal input."""

    try:
        x = eval(input("Please enter the number (>0) of piles of rocks >> "))
    except:
        raise Illegal

    if (type(x) != int) or (x <= 0):
        raise Illegal

    return x

def getPosition(posList,i):
    """This function asks user for an unselected position. It will raise Illegal for any illegal input."""

    try:
        x = eval(input("Enter the position (>0) for the "+str(i+1)+"th pile >> "))
    except:
        raise Illegal

    if (type(x) != int) or (x < 0):
        raise Illegal
    elif x not in posList:
        posList.append(x) # append a new number to the list
    else:
        raise Illegal


def main():
    # get the number of rock piles
    n = None
    while (True):
        try:
            n = getNumber()
        except Illegal:
            print("getNumber(): Your input is illegal.")
        else:
            break

    if n != None:
        # Get the positions of the n piles and enter them into a list.
        rockList = [] # create an empty list

        for i in range(n):
            while(True):
                try:
                    getPosition(rockList,i)
                except Illegal:
                    print("getPosition: Your input is illegal.")
                else:
                    break

        # Find a median of the inputted numbers.
        if len(rockList) == n:
            rockList = sorted(rockList)  # in case the inputted numbers are not sorted
            print("The position where all the rock piles should be moved to is ", rockList[int(len(rockList)/2)],".", sep="")

main()
