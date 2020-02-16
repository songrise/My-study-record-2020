def binary_search(list_: list, item: int):
    # binary search
    high = len(list_)-1
    low = 0
    mid = (high+low)//2
    while low <= high:
        mid = (high+low)//2
        if list_[mid] < item:
            low = mid+1
        elif list_[mid] > item:
            high = mid - 1
        else:
            return mid
    return "Not found"


theList = [1, 3, 4, 6, 7, 9, 13, 15, 16]
# the list must be sorted.
print(binary_search(theList, 14))

