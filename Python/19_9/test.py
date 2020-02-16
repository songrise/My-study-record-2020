try:
    n=int(input("please input a num ",))
    base=int(input("please input a base",)) 
except ValueError:
        print('invalid value')
   
for i in range (1,n):
    s=base*base

print("base^num=",s)      