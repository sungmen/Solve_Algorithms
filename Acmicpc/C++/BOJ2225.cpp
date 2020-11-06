#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    int dp[k+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= k; i++) dp[i][1] = dp[i-1][1] + 1;
    for (int i = 2; i <= k; i++) for (int j = 2; j <= n; j++) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    cout << dp[k][n];
}