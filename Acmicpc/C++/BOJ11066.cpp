#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin>>t;t--;) {
        int k; cin >> k;
        int tmp[k+2], tmp2[k+2], dp[k+2][k+2];
        memset(tmp, 0, sizeof(tmp));
        memset(tmp2, 0, sizeof(tmp2));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= k; i++) {
            cin >> tmp[i];
            tmp2[i] = tmp2[i - 1] + tmp[i];
        }
        for (int i = 2; i <= k; i++) {
            for (int j = i - 1; j > 0; j--) {
                dp[j][i] = 1e9;
                for (int p = j; p <= i; p++) {
                    dp[j][i] = min(dp[j][i], dp[j][p] + dp[p+1][i]);
                }
                dp[j][i] += tmp2[i] - tmp2[j - 1];
            }
        }
        cout << dp[1][k] << '\n';
    }
    return 0;
}