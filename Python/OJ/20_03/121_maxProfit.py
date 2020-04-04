class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if length == 0:
            return 0
        maxProf = 0
        minPric = prices[0]
        i = 1
        while (i < length):
            tdyPric = prices[i]
            if tdyPric < minPric:
                minPric = tdyPric
            else:
                tdyProf = tdyPric - minPric
                if tdyProf > maxProf:
                    maxProf = tdyProf
            i += 1

        return maxProf
