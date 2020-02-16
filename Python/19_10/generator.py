a = (a for a in range(9))
print(a)

def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield(3)
    print('step 3')
    yield(5)
o = odd()   
#调用该generator时，首先要生成一个generator对象，然后用next()函数不断获得下一个返回值：
next(o)
next(o)