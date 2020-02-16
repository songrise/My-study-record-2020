def main():

    number = 1

    rows = int(input("Enter number of rows: ")    )
    l = []
    odd = True
    s = 0
    for i in range(1, rows + 1):
        for j in range(1, i + 1):
            l.append(number)
            print(str(number) + " ", end="")
            if odd:
                s = s + number
            number = number + 1;
        odd = not odd
        print()

    number = 0
    l.reverse()
    for i in range(rows, 0, -1):
        for j in range(i, 0, -1):            
            print(str(l[number]) + " ", end="")
            if odd:
                s = s + l[number]
            number = number + 1;
        odd = not odd
        print()

    print("The sum of integers in odd row(s) is " + str(s))

main()
