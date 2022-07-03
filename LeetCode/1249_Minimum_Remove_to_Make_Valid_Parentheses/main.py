'''
    Runtime: 96 ms, faster than 83.23% of Python3 online submissions for Minimum Remove to Make Valid Parentheses.
    Memory Usage: 15.2 MB, less than 99.68% of Python3 online submissions for Minimum Remove to Make Valid Parentheses.

    url : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
'''

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        answer  = []
        for _, i in enumerate(s):
            if i == '(':
                stack.append(_)
            elif i == ')':
                if len(stack) > 0:
                    stack.pop()
                else:
                    answer.append(_)
        for i in stack:
            answer.append(i)        
        for i in answer[::-1]:
            if i == 0:
                s = s[1::]
            elif i == len(s)-1:
                s = s[:-1:]
            else:
                s = s[0:i:]+s[i+1::]
        return s