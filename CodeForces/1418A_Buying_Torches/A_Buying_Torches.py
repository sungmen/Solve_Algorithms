import sys
t = int(input())
for i in range(t):
    x, y, k = map(int, sys.stdin.readline().rstrip().split())
    sys.stdout.write(str((k+k*y+x-3)//(x-1)+k) + '\n')