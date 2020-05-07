def merge(lefthalf,righthalf):
    nlist = [0] * (len(lefthalf) + len(righthalf))

    i=j=k=0       
    while i < len(lefthalf) and j < len(righthalf):
        if lefthalf[i] < righthalf[j]:
            nlist[k]=lefthalf[i]
            i=i+1
        else:
            nlist[k]=righthalf[j]
            j=j+1
        k=k+1

    while i < len(lefthalf):
        nlist[k]=lefthalf[i]
        i=i+1
        k=k+1

    while j < len(righthalf):
        nlist[k]=righthalf[j]
        j=j+1
        k=k+1
        
    return nlist

def mergesort(x):
    if len(x) == 0 or len(x) == 1:
        return x
    else:
        middle = int(len(x)/2)
        a = mergesort(x[:middle])
        b = mergesort(x[middle:])
        return merge(a,b)

def main():

    aList = [10, 5, 2, 9, 6, 3, 4, 8, 1, 7]
    print(mergesort(aList))

    list1 = [1, 4, 6, 10]
    list2 = [5, 7, 8, 11, 12]
    print(merge(list1, list2))

main()
