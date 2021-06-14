import sys
from collections import deque as dq
# sys.stdin = open("input.txt", "r")
n, l = map(int, sys.stdin.readline().split())
d = list(map(int, sys.stdin.readline().split()))
dq = dq()
for _ in range(len(d)):
    while len(dq) > 0 and dq[-1][1] > d[_]:
        dq.pop()
    dq.append([_, d[_]])
    ran = _ - l + 1
    while ran >= 0 and dq[0][0] < ran:
        dq.popleft()
    sys.stdout.write(str(dq[0][1]) + " ")