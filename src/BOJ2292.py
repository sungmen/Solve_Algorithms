# BOJ2292.py

INIT = [i*6 for i in range(1, 18259)]
BEE = [1 for i in range(1, 18259)]
for i in range(1, 18258):
    BEE[i] = BEE[i-1]+INIT[i-1]

def com(n):
    for i in range(0, 18259):
        if n <= BEE[i]:
            return i+1

if __name__=="__main__":
    n = int(input())
    print(com(n))
