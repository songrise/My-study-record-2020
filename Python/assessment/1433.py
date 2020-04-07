all = []  # All case that x1 +x2 +x3 ==17
for i in range(1, 18):  # from 1 to 17
    for j in range(1, 18):
        for k in range(1, 18):
            if i+j+k == 17:
                all.append([i, j, k])  # use list to implement vector

ans = []  # Case that x1 +x2 <= 8
for case in all:
    if case[0] + case[1] <= 8:
        ans.append(case)


print("all:")
for i in range(len(all)):
    print(all[i], end="")
    if((i+1) % 5 == 0):
        print("\n")
print("Ans:")
for i in range(len(ans)):
    print(ans[i], end="")
    if((i+1) % 5 == 0):
        print("\n")

print(len(ans)/len(all))
