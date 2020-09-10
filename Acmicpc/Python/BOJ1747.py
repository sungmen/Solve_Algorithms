from sys import stdin, stdout
from math import sqrt

n = 1003001
a = [False, False] + [True] * (n-1)
palindromePrime = []

def isPalindrome(s):
    return  s == s[::-1]

def makePrime():
    for j in range(2, n+1):
        if a[j]:
            if (isPalindrome(str(j))):
                palindromePrime.append(j)
            for _ in range(2*j, n+1, j):
                a[_] = False

if __name__ == '__main__':
    makePrime()
    num = int(stdin.readline())
    for i in range(len(palindromePrime)):
        if num <= palindromePrime[i]:
            stdout.write(str(palindromePrime[i]))
            break
