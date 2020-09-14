from sys import stdin, stdout, maxsize

if __name__ == '__main__':
    T = int(stdin.readline().rstrip())
    arr = []
    for _ in range(T):
        arr.append(list(map(int, stdin.readline().rstrip().split())))
    v1 = []
    v2 = []
    ans = maxsize
    for i in range(int(1<<T)):
        v1.clear(), v2.clear()
        for j in range(T):
            if (i & (1 << j)) == 0:
                v1.append(j)
            else:
                v2.append(j)
        if (len(v1) > int(T//2)) or (len(v2) > int(T//2)):
            continue
        v1_v = v2_v = 0
        for _ in range(int(T//2)):
            for j in range(int(T//2)):
                if _ == j:
                    continue
                v1_v += arr[v1[_]][v1[j]]
                v2_v += arr[v2[_]][v2[j]]
        diff = abs(v1_v - v2_v)
        if ans > diff:
            ans = diff

    stdout.write(str(ans))