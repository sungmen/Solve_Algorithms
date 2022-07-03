class Solution:
    def getNumber(self, s:str) -> int:
        res = 0
        for _ in s:
            if _.isnumeric():
                res *= 10
                res += int(_)
            else:
                break
        return res
    
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        
        if len(s) == 0 or s[0] >= 'a' and s[0] <= 'z' or s[0] == '.':
            return 0
        minus = False
        res = 0
        if s[0] == '-':
            minus = True
            res = self.getNumber(s[1:])
        
        elif s[0] == '+':
            res = self.getNumber(s[1:])
            
        else:
            res = self.getNumber(s)
        
        if minus:
            res = -res
            if res < -2**31:
                res = -2**31
        
        if res > 2**31 - 1:
            res = 2 ** 31 - 1
        
        return res