def triangles():
    L = [1]
    while 1:
        yield L
        L = [0] + L + [0]
        L = [L[i] + L[i + 1] for i in range(len(L) - 1)]

#test
n = 0
results = []
for t in triangles(): #for xxx in (generator)
    results.append(t)
    n = n + 1
    if n == 10:
        break

for t in results:
    print(t)