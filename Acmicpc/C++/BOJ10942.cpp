#include <bits/stdc++.h>
using namespace std;
const int MAX = 2001;
int arr[MAX];
int dp[MAX][MAX];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) cin >> arr[i];
    for (int i = 1; i <= t; i++) dp[i][i] = 1;
    for (int i = 1; i < t; i++) if (arr[i] == arr[i+1]) dp[i][i+1] = 1;
    for (int i = 2; i < t; i++) {
        for (int j = 1; j <= t - i; j++) {
            if (arr[j] == arr[j+i] && dp[j+1][j+i-1]) {
                dp[j][j+i] = 1;
            }
        }
    }
    int m;
    for(cin>>m;m--;) {
        int s, e; cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    return 0;
}