#Q5

def addTable():

     table = []
     for i in range(10):
          row = []
          for j in range(10):
               if len(str(i+j)) == 1:
                    row.append("0"+str(i+j))
               else:
                    row.append(str(i+j))
          table.append(row)

     return table

def printAddTable(table):
     
     s = 6*" "
     u = 6*" "+10*"---"
     for i in range(10):
          s += "{:^3}".format(i)
     print(s)
     print(u)
     
     for i in range(10):
          s = "{0:3}{1:^3}".format(i,"|")
          for j in range(10):
               s += "{:3}".format(table[i][j])
          print(s)
     print()

def convert(input):
     if input[1] == "0":
          return int(input[0])
     else:
          return int(input)

def proc0(table, number1, number2):
     return table[number1][number2]


def main():
     table = addTable()
     
     while True:
          num1, num2= eval(input("Please enter two digits separated by a comma. \nEnter a negative digit to terminate: "))
          if num1 < 0 or num2 < 0:
               print("\tThank you for using the program.")
               break
          else:
               print("\tThe result of", str(num1)+"+"+str(num2), "is: ", convert(proc0(table,num1,num2)))     
          

main()

