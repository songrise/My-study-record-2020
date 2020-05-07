def main():
     symbol = input("Please enter a symbol: ")
     width = eval(input("Please enter the width, a positive integer: "))
     array = [" "]*width

     for i in range((width+1)//2):
          array[i], array[-1-i] = symbol, symbol
          for j in range(width):
               print(array[j], end="")
          print()

main()