import sys

# sys.stdin = open("input.txt", "r")

n = int(input())
sumArr = [0 for i in range(n)]
arr = []
memo = [0 for i in range(n)]
res = [0 for i in range(n)]
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    arr.append([b, a, i])

arr.sort(key=lambda x: (x[0], x[1]))
equ = 0
sam = 0
for i in range(n):
    sumArr[arr[i][1]-1] += arr[i][0]
    memo[i] += arr[i][0]
    if (i > 0):
        memo[i] += memo[i-1]
        if( arr[i][0] == arr[i-1][0]):
            equ += arr[i][0]
            if (arr[i][1] == arr[i-1][1]):
                sam += arr[i][0]
            else:
                sam = 0
        else:
            sam = 0
            equ = 0
    res[arr[i][2]] = (memo[i] - sumArr[arr[i][1]-1] - equ + sam)
for i in range(n):
    sys.stdout.write(str(res[i]) + '\n')
