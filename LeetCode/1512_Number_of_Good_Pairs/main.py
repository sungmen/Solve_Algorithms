class Solution:
    def __init__(self):
        self.arr = [0] * 101
        
    def numIdenticalPairs(self, nums: List[int]) -> int:
        for i in nums:
            self.arr[i] += 1
        res = 0
        for i in range(1, 101):
            if self.arr[i] > 0:
                res += self.arr[i] * (self.arr[i] - 1) / 2
        return int(res)
            