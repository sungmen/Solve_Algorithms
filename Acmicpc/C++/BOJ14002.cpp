#include <bits/stdc++.h>
using namespace std;
int DP[1001];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && DP[i] < DP[j] + 1) {
                DP[i] = DP[j] + 1;
                ans = max(ans, DP[i]);
            }
        }
    }
    if (ans == 0) {
        cout << 1 << '\n';
        cout << arr[n-1];
    } else {
        cout << ans << '\n';
        int res[n];
        memset(res, -1, sizeof(res));
        int tmp = n -1;
        for (int i = ans; i >= 1; i--) {
            for (int j = tmp; j >= 0; --j) {
                if (DP[j] == i && res[i] == -1) {
                    res[i] = arr[j];
                    tmp = j;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (res[i] == -1) break;
            else cout << res[i] << ' ';
        }
    }
}