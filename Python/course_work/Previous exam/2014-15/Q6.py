#Q6

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

'''def addTable():
     table = [['00', '01', '02', '03', '04', '05', '06', '07', '08', '09'],
              ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10'],
              ['02', '03', '04', '05', '06', '07', '08', '09', '10', '11'],
              ['03', '04', '05', '06', '07', '08', '09', '10', '11', '12'],
              ['04', '05', '06', '07', '08', '09', '10', '11', '12', '13'],
              ['05', '06', '07', '08', '09', '10', '11', '12', '13', '14'],
              ['06', '07', '08', '09', '10', '11', '12', '13', '14', '15'],
              ['07', '08', '09', '10', '11', '12', '13', '14', '15', '16'],
              ['08', '09', '10', '11', '12', '13', '14', '15', '16', '17'],
              ['09', '10', '11', '12', '13', '14', '15', '16', '17', '18']]
     return table'''


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

def proc1(table, number1, number2, number3):
     result_23 = proc0(table, number2, number3)
     result_1_23 = proc0(table, number1, int(result_23[1]))

     if result_1_23[0] == "0" and result_23[0] == "0":
          return "0"+result_1_23[1]
     elif result_1_23[0] == "1" and result_23[0] == "1":
          return "2"+result_1_23[1]
     else:
          return "1"+result_1_23[1]


def main():
     table = addTable()
     
     while True:
          num1, num2, num3= eval(input("Please enter three digits separated by a comma. \nEnter a negative digit to terminate: "))
          if num1 < 0 or num2 < 0:
               print("\tThank you for using the program.")
               break
          else:
               print("\tThe result of", str(num1)+"+"+str(num2)+"+"+str(num3), "is: ", convert(proc1(table,num1,num2,num3)))     
          

main()


