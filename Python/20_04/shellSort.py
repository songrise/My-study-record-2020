def shellSort(arr: list) -> list:
    shellIncrement = [109, 41, 19, 5, 1]
    len_ = len(arr)

    for inc in shellIncrement:
        for i in range(inc, len_):
            temp = arr[i]
            j = i
            while j >= inc:
                if arr[j-inc] > temp:
                    arr[j] = arr[j-inc]
                    j -= inc
                else:
                    break
                arr[j] = temp
    return arr


print(shellSort([1,4,2,12,5,9,123,7]))
