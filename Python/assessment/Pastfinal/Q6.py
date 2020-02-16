def solve() -> list:
    r, c = 0, 0
    ans = [0, 0]
    for r in range(1, 35+1):
        for c in range(1, 35+1):
            if (r+c == 35):
                if(4*r+2*c == 94):
                    # it should be brute-force as time complexity is o(N2)
                    ans[0], ans[1] = r, c
                    break
    return ans


def put(ans: list):
    print("Rabbits:{} Chicken:{}".format(ans[0], ans[1]))


def main():
    ans = solve()
    put(ans)


main()
