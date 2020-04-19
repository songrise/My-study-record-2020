class Solution:

    def findMinFibonacciNumbers(self, k: int) -> int:
        fib = [0 for _ in range(10000)]
        fib[0], fib[1] = 1, 1
        max_i = 0
        for i in range(2,10000):
            fib[i] = fib[i-1]+fib[i-2]
            if fib[i] > k:
                max_i = i
                break

        times = 0
        while k != 0:
            k -= fib[max_i-1]
            times += 1
            temp = 0
            for i in range(max_i):
                if fib[i] > k:
                    temp = i
                    break
            max_i = temp
        return times
