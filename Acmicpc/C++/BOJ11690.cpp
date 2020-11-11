#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e8+1;
long long MOD = 1;
int N;
bitset<MAX> DP;
void sieve() {
    for (int i = 4; i <= N; i+=2) {
        DP[i] = 0;
    } 
    for (int i = 3; i <= N; i+= 2) {
        if (DP[i]) {
            for (int j = i + i; j <= N; j += i) {
                DP[j] = 0;
            } 
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    MOD = MOD << 32; // 2^32
    DP.set();
    scanf("%d", &N);
    sieve();
    vector<int> v;
    v.emplace_back(2);
    for (int i = 3; i <= N; i+= 2) if (DP[i]) v.emplace_back(i);
    long long result = 1;
    for (auto i : v) {
        long long k = i;
        while (k * i <= N) k *= i;
        result = result * k % MOD;
    }
    printf("%lld", result);
    return 0;
}