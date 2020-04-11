cases = int(input())
ans = []

for i in range(cases):
    temp = list(map(lambda x: int(x), input().split()))
    n, m = temp[0], temp[1]
    r = []
    for i in range(n):
        if i == 0:
            r.append('W'+'B'*(m-1))
        else:
            r.append('B'*m)
    ans.append(r)


for i in ans:
    for t in range(len(i)):
        print(i[t])
