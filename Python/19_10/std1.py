import random
import math
def main():
    input = [random.randint(10, 100) for times in range(20)]
    output = []  
    #initialize
    def fun(x:list,y:list):
        sum = 0
        for num in x:
            sum += num
        avg = sum / len(x)
        sum = 0
        for num in x:
            sum += (num - avg)**2
        sd = math.sqrt(sum) 
        y.append(avg)
        y.append(sd)
    
    fun(input, output)
    input.sort()
    for line in range(1,5):
        for index in range(5*(line-1), 5*line):
            print("{:-4}".format(input[index]),end="")
        print("\n")
    print("Avg={:-4f}, SD={:-4f}".format(output[0], output[1]))
main()

        

