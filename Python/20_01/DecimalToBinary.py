
def dtb(num: int):
    if num < 2:
        print(num, end='')
    else:
        dtb(num//2)
        print(num % 2, end='')
# using an recursion because reversed output format


dtb(17)
