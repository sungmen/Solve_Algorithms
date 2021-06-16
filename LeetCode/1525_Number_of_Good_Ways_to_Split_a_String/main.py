class Solution:
    def numSplits(self, s: str) -> int:
        n = len(s)
        m1 = dict()
        m2 = dict()
        for _ in s:
            if not _ in m2:
                m2[_] = 1
            else:
                m2[_] += 1
        cnt = 0
        for _ in range(n - 1):
            if not s[0] in m1:
                m1[s[0]] = 1
            m2[s[0]] -= 1
            if m2[s[0]] == 0:
                del(m2[s[0]])
            s = s[1:]            
            if len(m1) == len(m2):
                cnt += 1
        return cnt