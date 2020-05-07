# (a)
def commonFactor(n1, n2) -> list:
    """
    A function to find common factors of n1 and n2
    Input: positive integers n1 and n2
    Output: return the list of common factors
   """

    f1 = set([f for f in range(2, n1+1) if n1 % f == 0])
    f2 = set([f for f in range(2, n2+1) if n2 % f == 0])
    return list(f1 & f2)


# (b)


def primeFactor(n):
    """
    A function to find and print the prime factors of n
    Input: positive integer n
    Output: return the list of prime factors
   """
    number = n

    def isPrime(num):
        if len([f for f in range(2, num+1) if num % f == 0]) == 1:
            return True
        else:
            return False

    factor = [f for f in range(2, n+1) if n % f == 0]
    ans = []

    i = 0
    while not isPrime(n):
        if (n % factor[i] == 0):
            ans.append(factor[i])
            n //= factor[i]
        else:
            i += 1

    ans.append(n)
    print("{} = {}".format(number, " * ".join([str(i) for i in ans])))
    return ans


# (c)

def LCM(numbers):
    """
    A function to find the LCM of a list of numbers
    Input: a list of positive integers
    Output: return the LCM of those numbers
   """

    def primeFactor_(n):

        number = n

        def isPrime(num):
            if len([f for f in range(2, num+1) if num % f == 0]) == 1:
                return True
            else:
                return False

        factor = [f for f in range(2, n+1) if n % f == 0]
        ans = []

        i = 0
        while not isPrime(n):
            if (n % factor[i] == 0):
                ans.append(factor[i])
                n //= factor[i]
            else:
                i += 1
        ans.append(n)
        return ans

    def LCM2num(a: int, b: int) -> int:
        fa = primeFactor_(a)
        fb = primeFactor_(b)
        for item in fb:
            while (fb.count(item) > fa.count(item)):
                fa.append(item)
        ans = 1
        for F in fa:
            ans *= F
        return ans

    answer = LCM2num(numbers[0], numbers[1])

    for i in range(2, len(numbers)):
        answer = LCM2num(answer, numbers[i])

    return answer


# (d)

def countAnimal(filename):
    """
    A function to open and read a file and count the number of occurrences of animals
    Input: the name of a text file
    Output: return a sorted list of tuples of animals and counts
   """
    with open(filename, 'r+') as text:
        text = text.read()
        text = text.split()
        AnimalList = sorted(["dog", "cat", "whale", "parrot",
                             "chicken", "sparrow", "fly", "butterfly", "bee"])
        ansList = [[name, 0] for name in AnimalList]

        for word in text:
            if word in AnimalList:
                ansList[AnimalList.index(word)][1] += 1

        ansTuple = [tuple(i) for i in ansList]

    return ansTuple


# (e)


def animalCategory(filename, category):
    """
    A function to read a file and count the number of occurrences of animals according to
   their category
    Input: the name of a text file and a dictionary of category
    Output: return a sorted list of tuples of animal categories and counts
   """
    freq = countAnimal(filename)
    ansList = [[k, 0] for k in category.keys()]

    for i in range(len(ansList)):
        class_ = ansList[i][0]
        animals = category[class_]
        for a in animals:
            for record in freq:
                if record[0] == a:
                    ansList[i][1] += record[1]
    ansList = sorted(ansList)
    ansTuple = [tuple(i) for i in ansList]
    return ansTuple


print("Part a")
print(commonFactor(12, 21))
print(commonFactor(60, 336))
print("==========")
print("Part b")
print(primeFactor(24))
print(primeFactor(31))
12
print(primeFactor(420))
print("==========")
print("Part c")
print(LCM([3, 4, 6, 10]))
print(LCM([2, 3, 8, 12, 16, 21]))
print("==========")
print("Part d")
AnimalList = ["dog", "cat", "whale", "parrot",
              "chicken", "sparrow", "fly", "butterfly", "bee"]
print(countAnimal("passage.txt"))
print("==========")
print("Part e")
categoryDict = {"mammal": ["dog", "cat", "whale"], "bird": [
    "parrot", "chicken", "sparrow"], "insect": ["fly", "butterfly", "bee"]}
print(animalCategory("passage.txt", categoryDict))
