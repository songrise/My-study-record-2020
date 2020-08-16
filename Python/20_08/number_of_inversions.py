def numInversions(number: str) -> int:
    # return the number of inversions of a given number, O(n^2)
    dp = [0]*len(number)
    if len(number) <= 1:
        return dp[-1]

    for i in range(1, len(dp)):
        number_of_larger = 0
        for j in range(i):
            if int(number[j]) > int(number[i]):
                number_of_larger += 1
        dp[i] = dp[i-1] + number_of_larger
    return dp[-1]


number = str(input("Please input the number(in decimal): "))

print("The number of inversions for "+number +
      " is " + str(numInversions(number)))
