import random

# create a set of people
allPeople = set(i for i in range(170))
# create a dict for all the people
friends = dict()
for person in allPeople:
    friends[person] = set()  # empty set

noFriendLinks = 0
while noFriendLinks < 800:
    # pick two people randomly
    twoFriends = random.sample(allPeople, 2)
    # check whether friends already
    if twoFriends[1] not in friends[twoFriends[0]]:
        friends[twoFriends[0]].add(twoFriends[1])
        friends[twoFriends[1]].add(twoFriends[0])
        noFriendLinks += 1

"""
# functions
def mostPopular(peopleDict):
    mostPopular = 0
    for person in peopleDict:
        if len(peopleDict[person]) > len(peopleDict[mostPopular]):
            mostPopular = person
    return mostPopular
"""

# functions


def mostPopular(peopleDict):
    """
    Input: dict is a dictionary of all people.
    Output: Return the people who are the most popular in the people in dict.
    """

    mostPopular = [0]
    for person in peopleDict:
        if len(peopleDict[person]) > len(peopleDict[mostPopular[0]]):
            mostPopular = [person]
        elif len(peopleDict[person]) == len(peopleDict[mostPopular[0]]):
            mostPopular.append(person)

    return mostPopular


# find out the most popular people
people = []
mostPopular = mostPopular(friends)
for person in mostPopular:
    people.append(str(person))

# calculate and print out the number of friendship links and each person's friends
size = 0
for person in allPeople:
    print(str(person)+":", friends[person])
    size += len(friends[person])
print()
print("The number of directional friendship links is:", size)

# print out the most popular persons and their number of friends
print("The most popular person is/are "+",".join(people)+".")
print("They/she/he has "+str(len(friends[mostPopular[0]]))+" friends.")
