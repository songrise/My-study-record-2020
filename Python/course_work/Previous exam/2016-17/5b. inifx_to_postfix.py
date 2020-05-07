from stackADT import *

def inToPost(inExp):
     """ To make it simple, the identifier's name is assumed to be a lower-case
     letter. The number is of single digit. """
     pri = {}
     pri["**"] = 4
     pri["*"] = 3
     pri["/"] = 3
     pri["+"] = 2
     pri["-"] = 2
     pri["("] = 1
     aStack = Stack()
     postList = []
     itemList = inExp.split()

     for item in itemList:
          if item in "abcdefghijklmnopqrstuvwxyz" or item in "0123456789":
               postList.append(item)
          elif item == '(':
               aStack.push(item)
          elif item == ')':
               top = aStack.pop()
               while top != '(':
                    postList.append(top)
                    top = aStack.pop()
          else:
               # for *, /, +, -
               if pri[item] != 4:
                    while (not aStack.isEmpty()) and (pri[aStack.peek()] >= pri[item]):
                         postList.append(aStack.pop())
                    aStack.push(item)
               # for ** (always push)
               else:
                    aStack.push(item)

     while not aStack.isEmpty():
          postList.append(aStack.pop())

     return " ".join(postList)

def main():
     expr = input("Please enter an arithmetic expression in which \
every item is separated by at least a space: ")
     print(inToPost(expr))

main()
