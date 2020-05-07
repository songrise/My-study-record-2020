#Q1

def list_sym(max, sym):
     slist = []
     for i in range(max+1):
          slist.append(i*sym)

     return slist[1:]

def main():
     sym = input("Please enter a symbol: ")
     max = eval(input("Please enter the maximum number of symbols: "))
     times = eval(input("Please enter the number of triangles: "))
     choice = input("Please specify how to print the triangle: \
                        \n\t '<' for right-angled triangle \
                        \n\t '>' for left-angled triangle \
                        \n\t '^' for two-equal-sided triangle\n")
     alist = list_sym(max, sym)
     for i in alist:
          for j in range(times):
               if choice == "<":
                    print("{:<{width}}".format(i, width = max), end="")
               elif choice == ">":
                    print("{:>{width}}".format(i, width = max), end="")
               elif choice == "^":
                    if max%2 == 0:
                         max -= 1
                    if len(i)%2 > 0:
                         print("{:^{width}}".format(i, width = max), end="")
               else:
                    print("Sorry, this choice is not valid.\n")
                    break
          if times > 0 and (choice != "^" or (choice == "^" and len(i)%2 > 0)):
               print()

main()
