#include <bits/stdc++.h>
using namespace std;
const int MOD = 987654321;
long long dp[5001];
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n; cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 5000; i++) {
        dp [i] = 0;
        for (int j = 0; j <= i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j] % MOD;
        }
        dp[i] %= MOD;
    }
    cout << dp[n/2];
    return 0;
}