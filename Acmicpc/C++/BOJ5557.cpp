#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	long long back[21];
	long long cur[21];
	memset(back, 0, sizeof(back));
	memset(cur, 0, sizeof(cur));
	back[nums[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (back[j]) {
				if (j + nums[i] >= 0 && j + nums[i] <= 20) {
					cur[j + nums[i]] += back[j];
				}
				if (j - nums[i] >= 0 && j - nums[i] <= 20) {
					cur[j - nums[i]] += back[j];
				}
			}
		}
		for (int j = 0; j <= 20; j++) {
			back[j] = cur[j];
		}
		memset(cur, 0, sizeof(cur));
	}
	cout << back[nums.back()];
	return 0;
}
