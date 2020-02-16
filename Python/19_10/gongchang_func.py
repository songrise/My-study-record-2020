def make_adder(n):
    def add(x):
        return x + n
    return add
    #返回自己的名字实际上是返回对自己的引用（函数名指向函数本身）
''' >>> plus_3 = make_adder(3)
>>> plus_5 = make_adder(5)

>>> plus_3(4)
7
>>> plus_5(4)
9'''