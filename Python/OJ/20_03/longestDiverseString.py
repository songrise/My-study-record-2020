class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        an = ['a' for i in range(a)]
        bn = ['b' for i in range(b)]
        cn = ['c' for i in range(c)]

        al = an+bn+cn
        for i in 'abc':
            al = sorted(al, key=lambda i: al.count(i))

        ans = ''
        len_ = a+b+c
        if(len_ < 3):
            return "".join(al)

        i = len_-1
        ans += al[i]
        ans += al[i-1]
        i -= 2

        j = 1
        while True:
            if ans[j] == ans[j-1]:
                k = i
                while k >= 0:
                    if al[k] != ans[j]:
                        ans += al[k]
                        al.remove(al[k])
                        break
                    elif k == 0:
                        return ans
                    k -= 1

            else:
                ans += al[i]

            i -= 1
            j += 1

            if i == 0:
                break
        return ans
