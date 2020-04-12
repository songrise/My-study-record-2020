class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        ans = []
        p = [i for i in range(1, m+1)]

        for i in range(len(queries)):
            j = p.index(queries[i])
            ans.append(j)
            p = [p[j]]+p[:j]+p[j+1:]

        return ans
