def harry(s:str,t:str):
    """Compare two strings.
       Print True if s and t contain identical letters else print false and print different letters. 
        s and t are two str, consisting only of lower case letters and space. 
"""
    print("Checking \"{}\" with \"{}\":".format(s,t),end='')
    S, T= sorted(list(s.replace(' ', ''))), sorted(list(t.replace(' ', ''))) 
    #Remove blank space and sort all letters in order to make comparison.
    if S == T:
        print(" True") 
    else:
        print(" False")
        times = {}      
        for y in T:
            times[y]= times.get(y, 0) - 1
        for x in S:
            times[x] = times.get(x, 0) + 1
        #Calculate the discrepancy of repeating times for every letters between two stra.
        for letters in times:
            if times[letters] == 0:
                continue
            print("Too {} {}".format("few" if times[letters] < 0 else "many", letters))
    return None

#Test           
harry("tom marvolo riddle", "i am lord voldemort")
harry("harry potter", "my hero part")
harry("a computer", "our pet mac")
