class Solution:
    def __init__(self):
        self.arr = [0] * (3 * int(1e4))
    
    def findDuplicate(self, nums: List[int]) -> int:
        for i in range (len(nums)):
            self.arr[nums[i]] = self.arr[nums[i]] + 1
            if self.arr[nums[i]] == 2:
                return nums[i]
        
        return 0