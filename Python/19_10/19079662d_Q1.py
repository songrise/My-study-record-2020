def passingAt(f,t):
    return (1-f)*(f**(t-1))

f, T = 0.1, 4
for i in range(1,T+1):
    print("f={}, Pr(T={})={}".format(f,i,passingAt(f,i)))

f, T = 0.2, 5
for i in range(1,T+1):
    print("f={}, Pr(T={})={}".format(f,i,passingAt(f,i)))

def passingBy(f,t):
    return 1-f**t

print("\n\nf={}, Pr(T<={})={}".format(0.1,4,passingBy(0.1,4)))
print("f={}, Pr(T<={})={}".format(0.2,5,passingBy(0.2,5)))

#if we use a loop to call the function passingAt(), we'll multiply 11 times.
#However, if we use passingBy(), we just multiply 4 times.

