class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        n = len(box)
        m = len(box[0])
        for _ in range(n):
            l = 0
            blk = 0
            cnt = 0
            while l < m:
                if box[_][l] == '#':
                    blk += 1
                if box[_][l] == '*':
                    for i in range(l-cnt, l-blk):
                        box[_][i] = '.'
                    for i in range(l-blk, l):
                        box[_][i] = '#'
                    cnt = 0
                    blk = 0
                else:
                    cnt+=1
                l += 1
            for i in range(l-cnt, l-blk):
                box[_][i] = '.'
            for i in range(l-blk, l):
                box[_][i] = '#'
        arr = [['.' for _ in range(n)] for i in range(m)]
        for _ in range(n):
            for j in range(m):
                arr[j][n-_-1] = box[_][j]
        return arr