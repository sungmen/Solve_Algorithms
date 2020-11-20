#include <bits/stdc++.h>
using namespace std;
long long dp[65][10];
long long res[65];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0 ; i < 10; i++) {
        dp[2][i] = i+1;
    }
    res[1] = 10;
    res[2] = 55;
    for (int i = 3; i <= 64; i++) {
        long long ans = 0;
        for (int  j = 0; j < 10; j++) {
            if (j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            ans += dp[i][j];
        }
        res[i] = ans;
    }
    int t;
    for (cin >> t; t--; ) {
        int n; cin >> n;
        cout << res[n] << '\n';
    }
    return 0;
}