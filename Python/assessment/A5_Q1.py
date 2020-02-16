def move(s1: str, s2: str):
    """ print according to 2 given states(CGMW).

    True if the move is legal and False otherwise. 
    It also prints the move if the move is legal and prints illegal move otherwise.
"""
    name = {0: 'Cabbage', 1: 'Goat', 2: 'Man',
            3: 'Wolf', 'E': 'east', 'W': 'west'}
    # Convert initials into full words.
    dif = []  # Store index of the different position between 2 states.

    print(s1, s2, end=" ")
    s1, s2 = list(s1), list(s2)
    for index in range(4):
        if s1[index] != s2[index]:  # find difference.
            dif.append(index)

    def legal():
        """judge where a move is legal, return True if legal"""
        if len(dif) > 2 or s2[2] != s2[1] == s2[0] or s2[2] != s2[1] == s2[3]\
           or s1[2] != s1[1] == s1[0] or s1[2] != s1[1] == s1[3]:  # according to MCGW constraints
            return False
        return True

    if not legal():
        print("Illegal move")
    elif len(dif) == 1:
        print("{} moves from {} to {}".format(
            name[dif[0]], name[s1[dif[0]]], name[s2[dif[0]]]))
        # dif[0] is an int, which is the index of list s1 and s2.
    else:  # len(dif) == 2
        print("{} and {} move from {} to {}"
              .format(name[dif[0]], name[dif[1]], name[s1[dif[0]]], name[s2[dif[0]]]))


# test
sol = ("EEEE", "EWWE", "EWEE", "WWWE", "WEEE", "WEWW", "WEEW", "WWWW")
for i in range(1, len(sol)):
    move(sol[i-1], sol[i])
print("\n")
sol = ("EEEE", "EWWE", "EWEE", "EWWE", "EWEE",
       "WWWE", "WEEE", "WEWW", "WEEW", "WWWW")
for i in range(1, len(sol)):
    move(sol[i-1], sol[i])
print("\n")
sol = ("EEEE", "EWWE", "EWEE", "WWWE", "WWEE", "WWWE", "EWEE", "WWWW")
for i in range(1, len(sol)):
    move(sol[i-1], sol[i])
