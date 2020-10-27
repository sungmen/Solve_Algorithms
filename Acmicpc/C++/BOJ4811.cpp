#include <bits/stdc++.h>
using namespace std;
long long dp[31][31];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if(j==0) dp[i][j] = 1;
            else if (j == i) dp[i][j] = dp[i][j-1];
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
        }
    }
    while (1) {
        int t; cin >> t;
        if(t == 0) return 0;
        cout << dp[t][t] << '\n';
    }
    return 0;
}