#include <bits/stdc++.h>
using namespace std;
int dp[21][21][21];
int op[21];
int t;
int sol (int num, int s, int e) {
    if (num > t) return 0;
    if (dp[num][s][e] != -1) return dp[num][s][e];
    dp[num][s][e] = min(abs(e-op[num]) + sol(num+1, s, op[num]), abs(s - op[num]) + sol(num+1, e, op[num]));
    return dp[num][s][e];
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int n, s, e; cin >> n >> s >> e;
    cin >> t;
    for (int i = 1; i <= t; i++) cin >> op[i];
    cout << sol(1, s, e);
    return 0;
}