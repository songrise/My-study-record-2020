import random

def randomInt(min, max, num):
     if type(max) != int or type(min) != int or type(num) != int:
          raise TypeError("TypeError: Max, min, and num must be of integer type.")
     if min > max:
          raise ValueError("ValueError: min must not be greater than max.")
     if max-min+1 < num:
          raise ValueError("ValueError: num cannot be less than max - min + 1")
     
     setInt = set()
     while len(setInt) != num:
          setInt.add(random.randrange(min, max+1))
          
     return tuple(sorted(setInt))

def main():

     print()
     print("The output for randomInt(10,10,0) is: ", randomInt(10,10,0))
     print()
     print("The output for randomInt(0,100,101) is: ", randomInt(0,100,101))
     print()
     print("The output for randomInt(0,100,50) is: ", randomInt(0,100,50))

     #These three test cases will be run for the exam grading
     # test case 1
     try:
          print("The output is: ", randomInt(10,"a",100))
     except Exception as err_msg:
          print(err_msg)
     # test case 2
     try:
          print("The output is: ", randomInt(101,100,100))
     except Exception as err_msg:
          print(err_msg)
     # test case 3
     try:
          print("The output is: ", randomInt(10,100,100))
     except Exception as err_msg:
          print(err_msg)

     # test case 4
     try:
          print("The output is: ", randomInt(10,100))
     except Exception as err_msg:
          print(err_msg)

     # test case 5
     try:
          print("The output is: ", randomInt(-10,100,100))
     except Exception as err_msg:
          print(err_msg)


main()
