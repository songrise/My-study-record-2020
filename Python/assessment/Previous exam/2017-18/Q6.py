def main():
    numheads = 35 
    numlegs = 94 
    solutions = solve(numheads,numlegs) 
    print(solutions)
    
def solve(numheads,numlegs): 
    i = 0
    j = 0
    for i in range(numheads + 1): 
         j = numheads - i 
         if 2 * i + 4 * j == numlegs: 
            return i,j 
    return 0, 0 
 
main()
