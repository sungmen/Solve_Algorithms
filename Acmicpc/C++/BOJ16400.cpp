#include <bits/stdc++.h>
using namespace std;
const int MOD = 123456789;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	bool pri_dp[40001];
	memset(pri_dp, true, sizeof(pri_dp));
	vector<int> pri;
	for (int i = 2; i < 40001; i++) {
		if (pri_dp[i]) {
			pri.emplace_back(i);
			for (int j = i + i; j < 40001; j += i) {
				if (pri_dp[j]) {
					pri_dp[j] = false;
				}
			}
		}
	}
	int n; cin >> n;
	int d[n+1];
	memset(d, 0, sizeof(d));
	d[0] = 1;
	for (int i = 0; i < pri.size(); i++) {
		for (int j = pri[i]; j <= n; j++) {
			d[j] = (d[j] + d[j - pri[i]]) % MOD;
			d[j] %= MOD;
		}
	}
	cout << d[n];
	return 0;
}
