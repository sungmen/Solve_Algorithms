from sys import stdin
from sys import stdout
try:stdin,stdout=open('input.txt','r'),open('out.txt','w')
except:pass
n, m = map(int, stdin.readline().split())
arr = [[i for i in stdin.readline()] for j in range(n)]
chk = [[False] * m for j in range(n)]
res = False
pos = [[0,1],[0,-1],[1,0],[-1,0]]

def dfs(startX, startY, x, y, cnt, col):
	global res
	for i in range(4):
		if res == True:
			return
		nextX, nextY = x + pos[i][0], y + pos[i][1]
		if nextX < 0 or nextX >= n or nextY < 0 or nextY >= m or arr[nextX][nextY] != col: 
			continue
		if cnt >= 4 and nextX == startX and nextY == startY:
			res = True
			return True
		if chk[nextX][nextY] == True:
			continue
		chk[nextX][nextY] = True
		dfs(startX, startY, nextX, nextY, cnt + 1, col)
		chk[nextX][nextY] = False
	return False

for i in range(n):
	for j in range(m):
		chk[i][j] = True
		dfs(i, j, i, j, 1, arr[i][j])
		if res:
			break
	if res:
		break

print('Yes' if res else 'No')
