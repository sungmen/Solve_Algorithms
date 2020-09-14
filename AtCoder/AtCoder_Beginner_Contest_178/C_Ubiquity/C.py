from sys import stdin, stdout

MOD = int(1e9+7)

if __name__ == '__main__':
    N = int(stdin.readline().rstrip())
    stdout.write(str((pow(10, N, MOD)-(2*pow(9, N, MOD))+pow(8, N, MOD))%MOD))