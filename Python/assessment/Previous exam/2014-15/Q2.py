#Q2

def func(min, max, opr):
     if min > max:
          raise ValueError("The min must not be greater than the max.")
          
     if opr == "+":
          return max + min
     elif opr == "-":
          return max - min
     elif opr == "*":
          return max * min
     elif opr == "/":
          if min == 0:
               raise ZeroDivisionError("Min cannot be zero for this operation.")
          else:
               return max / min
     else:
          raise ValueError("The operator", opr, "is not supported.")

def main():
     
     try:
          print("The result for func(10,20,'+'):  ", func(10,20,"+"))
     except ValueError as err_msg:
          print("The result for func(10,20,'+'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(10,20,'+'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(10,20,'+'):  ", err_msg)
     
     try:
          print("The result for func(20,10,'+'):  ", func(20,10,"+"))
     except ValueError as err_msg:
          print("The result for func(20,10,'+'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(20,10,'+'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(20,10,'+'):  ", err_msg)


     try:
          print("The result for func(20,10):      ", func(20,10))
     except ValueError as err_msg:
          print("The result for func(20,10):      ", err_msg)
     except TypeError as err_msg:
          print("The result for func(20,10):      ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(20,10):      ", err_msg)
          
     try:
          print("The result for func(20, '+'):    ", func(20, "+"))
     except ValueError as err_msg:
          print("The result for func(20, '+'):    ", err_msg)
     except TypeError as err_msg:
          print("The result for func(20, '+'):    ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(20, '+'):    ", err_msg)

          
     try:
          print("The result for func('a','b','-'):", func("a","b","-"))
     except ValueError as err_msg:
          print("The result for func('a','b','-'):", err_msg)
     except TypeError as err_msg:
          print("The result for func('a','b','-'):", err_msg)
     except SyntaxError as err_msg:
          print("The result for func('a','b','-'):", err_msg)
          
     try:
          print("The result for func(10,20,'-'):  ", func(10,20,"-"))
     except ValueError as err_msg:
          print("The result for func(10,20,'-'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(10,20,'-'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(10,20,'-'):  ", err_msg)

     try:
          print("The result for func(10,20,'*'):  ", func(10,20,"*"))
     except ValueError as err_msg:
          print("The result for func(10,20,'*'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(10,20,'*'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(10,20,'*'):  ", err_msg)

     try:
          print("The result for func(10,20,'/'):  ", func(10,20,"/"))
     except ValueError as err_msg:
          print("The result for func(10,20,'/'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(10,20,'/'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(10,20,'/'):  ", err_msg)

     try:
          print("The result for func(0,20,'/'):   ", func(0,20,"/"))
     except ValueError as err_msg:
          print("The result for func(0,20,'/'):   ", err_msg)
     except TypeError as err_msg:
          print("The result for func(0,20,'/'):   ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(0,20,'/'):   ", err_msg)
     except ZeroDivisionError as err_msg:
          print("The result for func(0,20,'/'):   ", err_msg)

     try:
          print("The result for func(10,20,'^'):  ", func(10,20,"^"))
     except ValueError as err_msg:
          print("The result for func(10,20,'^'):  ", err_msg)
     except TypeError as err_msg:
          print("The result for func(10,20,'^'):  ", err_msg)
     except SyntaxError as err_msg:
          print("The result for func(10,20,'^'):  ", err_msg)




main()
