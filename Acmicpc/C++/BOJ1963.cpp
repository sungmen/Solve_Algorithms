#include <bits/stdc++.h>
using namespace std;
int main() {
	// freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	vector<int> d(10000, true);
	vector<string> pri;
	map<string, int> pri_m;
	int cnt = 0;
	for (int i = 2; i < 10000; i++) {	// sieve of eratosthenes
		if (d[i]) {
			if (i > 1000) {
				string str = to_string(i);
				pri.push_back(str);
				pri_m[str] = cnt++;
			}
			for (int j = i + i; j < 10000; j += i) {
				d[j] = false;
			}
		}
	}
	int t; cin >> t;	// TestCase
	while(t--) {
		queue<pair<string, int>> q;
		int s, e; cin >> s >> e;
		q.push({to_string(s), 0});
		bool find = false;
		vector<bool> chk(pri.size(), false);
		int end = pri_m.find(to_string(e))->second;
		while(!q.empty()) {
			pair<string, int> cur = q.front();
			q.pop();
			int chk_n = pri_m.find(cur.first)->second;
			if (chk[chk_n]) continue;
			chk[chk_n] = true;
			if (cur.first == to_string(e)) {
				cout << cur.second << '\n';
				find = true;
				break;
			}
			for (int i = 0; i <= 9; i++) {
				for (int j = 0; j < 4; j++) {
					string tmp = cur.first;
					tmp[j] = char(i+'0');
					if (tmp != cur.first && pri_m.find(tmp) != pri_m.end() && !chk[pri_m.find(tmp)->second]) {
						q.push({tmp, cur.second+1});
					}
				}
			}
		}
		if (!find) cout << "Impossible\n";
	}
	return 0;
}