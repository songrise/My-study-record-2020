class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        allCase = ["a", "b", "c"]
        for i in range(1, n):
            for j in range(len(1, allCase)):
                case = allCase.pop(0)
                if case[-1] != "a":
                    allCase.append(case+"a")
                if case[-1] != "b":
                    allCase.append(case+"b")
                if case[-1] != "c":
                    allCase.append(case+"c")

        if k > len(allCase):
            return ""
        else:
            return allCase[k-1]
