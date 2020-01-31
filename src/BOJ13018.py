# https://www.acmicpc.net/problem/13018
# BOJ13018.py

from sys import stdin
from sys import stdout

def sequence(n, k):
    d = n - k
    arr = [i for i in range(1, n+1)]
    if n == k:
        stdout.write('Impossible' + '\n')
    elif d == 1:
        for i in arr:
            stdout.write(str(i) + ' ')
        stdout.write('\n')
    else:
        for i in range(1, d):
            arr[i-1], arr[i] = arr[i], arr[i-1]
        for i in arr:
            stdout.write(str(i) + ' ')
        stdout.write('\n')

if __name__=="__main__":
    n, k = map(int, stdin.readline().split())
    sequence(n, k)
