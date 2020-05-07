def LCM2(a: int, b: int) -> int:
    fa = [f for f in range(2, a+1) if a % f == 0]
    fb = [f for f in range(2, b+1) if b % f == 0]
    for item in fb:
        while (fb.count(item) == fa.count(item)):
            fa.append(item)
    ans = 1
    for F in fa:
        ans *= F
    return ans


print(LCM2(4, 9))
