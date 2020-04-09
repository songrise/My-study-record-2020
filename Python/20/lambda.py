
x = lambda y: y*y-1

def wrapper(func, arg):
    print("function called with argument: ",arg)
    val= x(arg)
    print("function returned: ",val)

wrapper(x,4)