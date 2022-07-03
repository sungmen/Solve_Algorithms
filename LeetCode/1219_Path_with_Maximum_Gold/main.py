class Solution:
    def __init__(self):
        self.m = 0
        self.n = 0
    
    def dfs(self, y, x, grid) -> int:
        if y < 0 or y >= self.m or x < 0 or x >= self.n or grid[y][x] == 0:
            return 0
        res = 0
        tmpGrid = grid[y][x]
        grid[y][x] = 0
        for y_, x_ in ((y, x - 1), (y, x + 1), (y - 1, x), (y + 1, x)):
            res = max(self.dfs(y_, x_, grid), res)
        grid[y][x] = tmpGrid
        return grid[y][x] + res
        
    
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        res = max(self.dfs(i, j, grid) for i in range(self.m) for j in range(self.n))
        return res