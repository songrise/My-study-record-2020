import time


def binary_search(list,item):
    s=time.time()
    low=0
    high=len(list)-1

    while low <=high:
        mid=int((low+high)/2)
        guess=list[mid]
        if guess == item:
            return mid
        if guess > item:
            high= mid-1
        if guess < item:
            low=mid+1
    e=time.time()
    print("time elipsed:",e-s)      



mu=[1,3,4,34,345,54,6,765,7,65,234,55,87,8,657,2342,3456,66645,453]  

print(binary_search(mu,6))
        