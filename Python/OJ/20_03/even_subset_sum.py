cases = int(input())
ans = []
for i in range(cases):
    len_ = int(input())
    arr = list(map(lambda x: int(x), input().split()))

    rarr = []
    sum_ = 0
    for j in range(len_):
        rarr.append(j+1)
        sum_ += arr[j]
        if arr[j] % 2 == 0:
            rarr = [j+1]
            break

        if (sum_ % 2 == 0):
            break
        elif j == len_-1:
            rarr = []

    ans.append(rarr)

for item in ans:
    rlen = len(item)
    if rlen != 0:
        print(rlen)
        for i in range(rlen):
            print(item[i], end=" ")
        print()
    else:
        print(-1)
