len = int(input())

arr = input().split(" ")

for i in range(len):
    arr[i] = int(arr[i])

max = arr[0]

for i in range(1, len):
    temp = arr[i-1]
    if temp > max:
        max = temp

    arr[i] += max

for i in range(len):
    print(arr[i], end=' ')
