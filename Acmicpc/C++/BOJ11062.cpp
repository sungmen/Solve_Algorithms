#include <bits/stdc++.h>
using namespace std;
int card[1001];
int dp[1001][1001][2];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> card[i];
            dp[i][i][0] = card[i];
            dp[i][i][1] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                int k = i + j;
                dp[j][k][0] = max(card[k] + dp[j][k-1][1], card[j] + dp[j+1][k][1]);
                dp[j][k][1] = min(dp[j][k-1][0], dp[j+1][k][0]);
            }
        }
        cout << dp[0][n-1][0] << '\n';
    }
    return 0;
}