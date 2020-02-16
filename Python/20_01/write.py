def main():
    with open("20_01\\test.txt", "r") as infile:
        data = infile.read()
        print(len(data))
        print(data)
        for i in range(len(data)):
            print(data[i], ord(data[i]), end='')
    print("\n###################")
    with open("20_01\\test.txt", "r") as infile:
        for i in range(3):
            # for i in infile.readlines():
            line = infile.readline()
            print(len(line))
            print(line[:-1])  # tail character removed

    print("\n###################")
    with open("20_01\\test.txt", "r") as infile:
        for line in infile.readlines():
            # readlines return a list.
            print(len(line))
            print(line)


main()
