cases = int(input())
ans = []

for i in range(cases):
    len_ = int(input())
    arr = []
    for i in range(len_):
        arr.append(list(map(lambda x: int(x), input().split())))

    status = "YES"

    for i in range(len_):
        if (arr[i][0] < arr[i][1]):
            status = "NO"
            break
        elif(i > 0):
            if((arr[i][0] < arr[i-1][0]) or (arr[i][1] < arr[i-1][1])):
                status = "NO"
                break
            if ((arr[i][0] == arr[i-1][0]) and (arr[i][1] > arr[i-1][1])):
                status = "NO"
                break

    ans.append(status)


for item in ans:
    print(item)
