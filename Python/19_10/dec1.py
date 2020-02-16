import time

def timeit(func):
    def wrapper(*arg,**kwargs):
        a=time.time()
        func()
        b=time.time()
        print("time elipsed {}",b-a)
        return func()
    return wrapper

@timeit
def adder():
    for i in range(1,100):
        i*=i+1
    print(i)


adder()

