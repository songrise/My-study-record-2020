class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i in range(len(words)):
            for w in words:
                if (words[i] in w and words[i] != w):
                    ans.append(words[i])
        ans = list(set(ans))
        return ans
