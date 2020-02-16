def yell(text):
    return text.upper()+'!'

print(yell('hello'))
 
bark=yell
print(bark('hello'))
print(bark.__name__)

funcs=[bark,str.lower,str.capitalize]
print(funcs)

def greet(func):#func is a function object
    greeting=func('Hi, i am a python programme')
    print(greeting)
#decorator??
greet(bark)

print("------------\n")
#nested function
def get_speak_func(volume):
    def whisper(text):
        return text.lower() + '...'
    def yell(text):
        return text.upper() + '!'
    if volume > 0.5:
        return yell#yell 指yell（）的返回值
    else:
        return whisper
#例如，上面这个函数定义了两个内部函数。顶层函数根据传递进来的参数向调用者返回对应的内部函数：
#函数也是对象
#注意，get_speak_func实际上不调用任何内部函数，只是根据volume参数选择适当的内部函数，然后返回这个函数对象
#但是怎么向内层函数传参数呢？？？
def get_speak_func2(text, volume):
    def whisper():
        return text.lower() + '...'
    def yell():
        return text.upper() + '!'
    if volume > 0.5:
        return yell
    else:
        return whisper
#仔细看看内部函数whisper和yell，注意其中并没有text参数。但不知何故，内部函数仍然可以访问在父函数中定义的text参数。它们似乎捕捉并“记住”了这个参数的值。
#拥有这种行为的函数被称为词法闭包（lexical closure），简称闭包。闭包在程序流不在闭包范围内的情况下，也能记住封闭作用域（enclosing scope）中的值。