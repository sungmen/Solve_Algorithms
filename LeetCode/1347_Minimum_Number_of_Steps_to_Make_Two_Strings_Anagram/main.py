class Solution:
    def minSteps(self, s: str, t: str) -> int:
        res = 0
        dic = {}
        for _ in s:
            if _ in dic:
                dic[_] += 1
            else:
                dic[_] = 1
        for _ in t:
            if _ in dic:
                dic[_] -= 1
                if not dic[_]:
                    del dic[_]
            else:
                res += 1
        return res