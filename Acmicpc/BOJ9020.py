# BOJ9020.py

from sys import stdout

def is_prime(n):
    for _ in range(2, int(n**0.5+1)):
        if n % _ == 0:
            return False
    return True

if __name__=="__main__":
    for _ in range(int(input())):
        n = int(input())
        i = n // 2
        j = 4
        while True:
            if is_prime(i):
                j = n - i
            if is_prime(j):
                stdout.write(str(i) + ' ' + str(j) + '\n')
                break
            i -= 1
