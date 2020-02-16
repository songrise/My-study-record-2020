def merge(lefthalf: list, righthalf: list) -> list:
    ans = []
    i, j = 0, 0  # index for each half
    # print(len(lefthalf), len(righthalf), i, j)
    for t in range(len(lefthalf)+len(righthalf)):
        if (i < len(lefthalf) and j < len(righthalf) and lefthalf[i] <= righthalf[j]):
            ans.append(lefthalf[i])
            i += 1
        elif (i < len(lefthalf) and j < len(righthalf) and lefthalf[i] > righthalf[j]):
            ans.append(righthalf[j])
            j += 1

    return ans


def mergesort(x):
    if len(x) == 0 or len(x) == 1:
        return x
    else:
        middle = int(len(x)/2)
        a = mergesort(x[:middle])
        b = mergesort(x[middle:])
        return merge(a, b)


def main():
    aList = [10, 5, 2, 9, 6, 3, 4, 8, 1, 7]
    print(mergesort(aList))
    list1 = [1, 4, 6, 10]
    list2 = [5, 7, 8, 11, 12]
    print(merge(list1, list2))


main()
