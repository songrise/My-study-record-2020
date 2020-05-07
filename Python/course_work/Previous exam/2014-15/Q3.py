#Q3
import math

def main():
     term = 1

     for i in range(8):
          term = math.sqrt(2+term)

     pi = 768 * math.sqrt(2-term)

     print("\nThe estimated pi is: {0:0.30f}.".format(pi))
     print("The actual pi is:    {0:0.30f}.\n".format(math.pi))

main()
          
