def double():
    with open("20_01\\double.txt", 'r+') as f:
        i = []
        for line in f.readlines():
            i.append(2*int(line))
        for item in i:
            f.write("\n")
            f.write(str(item))


double()
