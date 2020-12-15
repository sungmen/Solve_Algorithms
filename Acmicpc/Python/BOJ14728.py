import sys

n, t = map(int, sys.stdin.readline().split())

t_arr = []
score = []

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    t_arr.append(x)
    score.append(y)

dp = [[0 for i in range(t + 1)] for i in range(n + 1)]
for i in range(n + 1):
    for j in range(t + 1):
        if i == 0 or j == 0:
            dp[i][j] = 0
        elif t_arr[i - 1] <= j:
            dp[i][j] = max(score[i-1] + dp[i-1][j-t_arr[i-1]], dp[i-1][j])
        else:
            dp[i][j] = dp[i - 1][j]

print(dp[n][t])


