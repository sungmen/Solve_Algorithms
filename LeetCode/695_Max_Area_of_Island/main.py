class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        chk = [[False for _ in range(n)] for i in range(m)]
        pos = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        res = 0
        for i in range(m):
            for j in range(n):
                if (chk[i][j] == False and grid[i][j] == 1):
                    tmpSum = 0
                    q = []
                    q.append([i, j])
                    chk[i][j] = True
                    while len(q) != 0:
                        cur = q.pop(0)
                        tmpSum += 1
                        for _ in range(4):
                            y_ = cur[0] + pos[_][0]
                            x_ = cur[1] + pos[_][1]
                            if (y_ < 0 or x_ < 0 or y_ >= m or x_ >= n or chk[y_][x_] or grid[y_][x_] != 1):
                                continue
                            chk[y_][x_] = True
                            q.append([y_, x_])
                    if res < tmpSum:
                        res = tmpSum
        return res
        