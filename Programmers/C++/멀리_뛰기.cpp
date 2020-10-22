#include <bits/stdc++.h>
const int MOD = 1234567;
using namespace std;
long long solution(int n) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int fib[2001];
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    return fib[n];
}