def crypto(m: str, N: int, order: tuple):
    """encrypt/decrypt from user input

    return a str
"""

    def z_fill(target: list,):
        """fill blank with letter 'z'"""
        nonlocal m, N
        for index in range(len(target)):
            if len(target[index]) < len(m)/N:
                target[index] += 'z'

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
        nonlocal m, N, order
        # creat a matrix for encryption. Also can use 2-dimension list
        column = [m[i:len(m):N] for i in range(N)]
        z_fill(column)
        m = ""
        for n in range(N):
            m += "".join(column[order[n]-1])
        return m

    def decrypt():
        nonlocal m, N, order
        row = int(len(m)/N) if len(m) % N == 0 else len(m)//N+1
        column = [0 for n in range(N)]  # 0 is just a placeholder
        n = 1  # varible n is used for slice
        for i in range(N):  # 37-40 created a matrix for decryption
            column[order[i]-1] = m[(n-1)*row:n*row]
            n += 1
        z_fill(column)
        m = ""
        for row_index in range(row):  # 42-44 decode the matrix
            for slice_ in column:
                m += slice_[row_index]
        return m

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
print(crypto("ordpfhntanlntpoeeondtanayteimieaolrbffkz", 4,
             (2, 3, 1, 4)))
# user inputs b D in that order
print(crypto("harrypotterandvoldemort", 5, (2, 1, 4, 3, 5)))
# user inputs e
