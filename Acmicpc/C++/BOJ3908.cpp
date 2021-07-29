#include <bits/stdc++.h>
using namespace std;
int prime[1121];
int dp[15][1121];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(prime, 1, sizeof(prime));
    map<int, int> m;
    for (int i = 2; i < 1121; i++) {
        if (prime[i]) {
            m[i] = 1;
            for (int j = i + i; j < 1121; j += i) {
                if (prime[j]) {
                    prime[j] = 0;
                }
            }
        }
    }
    dp[0][0] = 1;
    int cnt = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        for (int i = 1120; i >= it->first; --i) {
            for (int j = 1 ; j <= 14; j++) {
                dp[j][i] += dp[j - 1][i - it->first];
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << dp[k][n] << '\n';
    }
    return 0;
}