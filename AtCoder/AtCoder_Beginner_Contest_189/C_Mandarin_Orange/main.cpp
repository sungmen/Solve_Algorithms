#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	int res[n];
	pair<long, long> dp[n];
	memset(dp, 0, sizeof(dp));
	long long MAX = 0;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		res[i] = t;
		dp[i] = {t, t};
		for (int j = 0; j < i; j++) {
			dp[j].second = dp[j].second > t ? t : dp[j].second;
			dp[j].first = dp[j].second * (i - j + 1);
			if (res[j] < dp[j].first) res[j] = dp[j].first;
		}
	}
	for (int i = 0; i < n; i++) {
		MAX = MAX < res[i] ? res[i] : MAX;
	}
	cout << MAX;
	return 0;
}
