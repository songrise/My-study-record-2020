def main():
    def addTable():
        """return a addition table implemented as a list of lists."""
        add_table = [[] for n in range(10)]
        start = 0  # First number in each sublist.
        for i in range(len(add_table)):  # range(10). i is index.
            for num in range(start, start+10):
                add_table[i].append("{:0>2d}".format(num))
            start += 1
        return add_table

    table = addTable()
    for item in table:
        print(item)


main()
