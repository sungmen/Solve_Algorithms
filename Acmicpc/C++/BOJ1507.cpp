#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int d[n][n], chk[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> d[i][j];
    memset(chk, 1, sizeof(chk));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i==j||i==k||j==k) continue;
                else if (d[i][k] + d[k][j] < d[i][j]) {
                    cout << -1;
                    return 0;
                }
                else if (d[i][j] == d[i][k] + d[k][j]) {
                    chk[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(chk[i][j]) {
                ans += d[i][j];
            }
        }
    }
    cout << ans / 2;
}