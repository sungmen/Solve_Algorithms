# BOJ9613.py
from math import gcd
from sys import stdin
from sys import stdout

if __name__ == "__main__":
    for _ in range(int(input())):
        n, *a = map(int, stdin.readline().split())
        sum = 0
        for i in range(n-1):
            for j in range(i+1, n):
               sum += gcd(a[i], a[j])
        stdout.write(str(sum) + '\n') 
