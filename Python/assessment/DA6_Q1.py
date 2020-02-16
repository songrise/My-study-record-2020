def crypto(m: str, N: int, order: tuple):
    """encrypt/decrypt from user input"""

    def valid_choice():
        """ judge if an input is valid,
        return the"""
        while 1:
            trial = input().capitalize()
            if trial != 'E' and trial != 'D':
                print("Invalid choice, please try again:", end="")
                continue
            return trial

    def encrypt():
        nonlocal m, N, order, column
        hang = len(m)//N
        i = 0
        for n in range(len(column)):  # 似乎E不用考虑无法整除
            for letters in m[i:len(m):N]:
                # print("#\n{}\n#".format(column[i]))
                (column[i]).append(letters)
            i += 1
        n, c, m = 0, 0, ""
        for n in range(N):
            m += "".join(letters for letters in column[order[c]-1])
            c += 1
        return m

    def decrypt():
        nonlocal m, N, order, column
        for times in range(N):
            i = 0
            hang = len(m)//N

        pass

    column = [[]for n in range(N)]
    print("Please enter your choice (E/D):", end="")
    if valid_choice() == 'E':
        return encrypt()
    else:  # valid_choice() == 'D'
        return decrypt()


print(crypto("hellohowdoyoudo", 3, (1, 2, 3)))
# user inputs a b e in that order
print(crypto("hellohowdoyoudo", 3, (2, 3, 1)))
# user inputs a b e in that order
print(crypto("eowydlhdoohloou", 3, (2, 3, 1)))
# user inputs b C D in that order
