def main():
     text = input("\nPlease input a string: ")
          
     lst = text.split()
     if text[-1] == ".":
        lst[0] += "."
        lst[len(lst)-1] = lst[len(lst)-1][0:-1]

     newtext = " ".join(lst[::-1])
     print("The correct output is:", newtext, "\n")
     
main()
