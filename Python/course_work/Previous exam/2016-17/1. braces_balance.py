from stackADT import *

def main():
     expr = input("Please enter the combination of braces: ")
     s = Stack()
     open_braces = "([{"
     close_braces = ")]}"
     balanced = True
     index = 0
     while index < len(expr) and balanced:
          symbol = expr[index]
          # open braces
          if symbol in open_braces:
               s.push(symbol)
          # close braces
          else:
               if s.isEmpty():
                    balanced = False
               else:
                    top = s.pop()
                    if open_braces.index(top) != close_braces.index(symbol):
                         balanced = False
          index = index + 1

     if balanced and s.isEmpty():
           print("The result is True.")
     else:
           print("The result is False.")

main()
