from sys import stdin
from sys import stdout
from math import gcd
try:stdin,stdout=open('input.txt','r'),open('out.txt','w')
except:pass
if __name__ == "__main__":
    for _ in range(int(stdin.readline())):
        n = int(stdin.readline())
        for i in range(n, n+100):
            if (gcd(i, sum(list(map(int, str(i)))))) > 1:
                stdout.write(str(i) + '\n')
                break