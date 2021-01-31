#include <bits/stdc++.h>
using namespace std;
bool priCheck(int n) {
	for (int i = 2; i < int(sqrt(n)) + 1; i++) {
		if (!(n % i)) return false;
	}
	return true;
}
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	vector<int> res;
	for (int i = 2; i <= 9; i++) {
		if (priCheck(i)) {
			queue<pair<int, int>> q;
			q.push({i, 1});
			while(!q.empty()) {
				pair<int ,int> cur = q.front();
				q.pop();
				if (cur.second == n) {
					res.push_back(cur.first);
					continue;
				}
				int tmp = cur.first * 10;
				for (int i = 0; i <= 9; i++) {
					if (priCheck(tmp + i)) {
						q.push({tmp + i, cur.second + 1});
					}
				}
			}
		}
	}
	for (auto i : res) {
		cout << i << '\n';
	}
	return 0;
}
