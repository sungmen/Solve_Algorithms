#include <bits/stdc++.h>
using namespace std;
int const MIN = -1e9;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	int d[n]; 
	for (int i = 0; i < n; i++) cin >> d[i];
	int dp[4][n+1];
	for (int i = 0; i < 4; i++) for (int j = 0; j <= n; j++) dp[i][j] = MIN;
	for (int i = 0; i < 4; i++) {
		for (int j = n - 1 - i; j >= 0; --j) {
			if (!i) dp[i][j] = max(dp[i][j+1], d[j]);
			else if (i == 1 || i == 3) dp[i][j] = max(dp[i][j+1], dp[i-1][j+1] - d[j]);
			else dp[i][j] = max(dp[i][j+1], dp[i-1][j+1] + d[j]);
		}
	}
	cout << dp[3][0];
	return 0;
}
