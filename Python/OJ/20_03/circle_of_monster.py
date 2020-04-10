cases = int(input())
ans = []

for i in range(cases):
    monsterNum = int(input())
    a = []
    for k in range(monsterNum):
        a += list(map(lambda x: int(x), input().split()))

    shoot = 0
    n = 1
    minHP = a[0]
    while n < monsterNum*2:
        #a[i] is explode
        minHP = min(minHP, a[n-1])
        if(n != monsterNum*2-1):
            if (a[n] < a[n+1]):  # explode less next hp
                shoot += a[n+1]-a[n]
        else:  # last monster
            if (a[n] < a[0]):
                shoot += a[0]-a[n]

        n += 2

    shoot += minHP
    ans.append(shoot)

for i in range(cases):
    print(ans[i])
