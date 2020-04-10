cases = int(input())
ans = []

for i in range(cases):
    temp = list(map(lambda x: int(x), input().split()))
    len_, low = temp[0], temp[1]
    arr = (list(map(lambda x: int(x), input().split())))

    arr.sort()
    sum_ = sum(arr)

    for k in range(len_):
        remain = len_-k
        avg = sum_/remain
        if (avg >= low):
            ans.append(remain)
            break

        sum_ -= arr[k]
        remain -= 1

        if(k == len_-1):
            ans.append(0)


for item in ans:
    print(item)
