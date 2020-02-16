import math

def rootTwo(n):
    x=0
    for count in range(1,n):
        x=1/(2+x)
    return x+1
#BTW I tried to use recursion, but I couldn't work it out.

print("RootTwo={}".format(math.sqrt(2)))
for i in range(1,6):
    value = rootTwo(i)    
    print( "Value with {} terms={}, error={}".\
        format(i,value,abs(math.sqrt(2)-value)))

#As the term(s) increase, the absolute value of error is decresing
#that means our approximation is getting closer to the real value of root2.