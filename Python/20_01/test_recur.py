def recur1(num: int):
    # recurison without return, only push in stack without poping;
    if num > 5:
        return "passed"  # 只有栈顶有返回值，中间返回是NOne。
    recur1(num+1)
    print("This is {}th recursion ".format(num))


def recur2(num: int):
    # recurison without return, only push in stack without poping;
    if num > 5:
        return "passed"
    return recur2(num+1)  # return 可以将栈顶值逐级返回至栈底。
    print("This is {}th recursion ".format(num))


def recur3(num: int):
    if num == 6:
        return num
    else:
        num = recur3(num+1)
        print("num = {}".format(num))


print("recursion without return.")
recur1(0)
print(recur1(0))

print("\nrecursion with return.")
recur2(0)
print(recur2(0))

print("\n recursion with only last returned")
print(recur3(0))
