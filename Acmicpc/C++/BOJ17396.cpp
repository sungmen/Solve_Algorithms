#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<bool> vi(n);
    for (int i = 0; i < n; ++i) {
		bool c; cin >> c;
		vi[i] = c;
	}
	if (vi[0]) {
		cout << -1;
		return 0;
	}
	vi[n-1] = 0;
    vector<vector<pll>> vp(n);
	vector<long long> dist(n, LONG_MAX);
	for (int i = 0; i < m; ++i) {
		int a, b, c; cin >> a >> b >> c;
		if (vi[a] || vi[b]) continue;
		vp[a].emplace_back(b, c);
		vp[b].emplace_back(a, c);
	}
	dist[0] = 0;
	priority_queue<pll> pq;
	pq.emplace(0, 0);
	while (! pq.empty()) {
		pll cur = pq.top();
		pq.pop();
		cur.first = -cur.first;
		if (dist[cur.second] < cur.first) continue;
		for (int i = 0; i < vp[cur.second].size(); ++i) {
			pll next = {vp[cur.second][i].second + cur.first, vp[cur.second][i].first};
			if (dist[next.second] > next.first && dist[cur.second] != LONG_MAX) {
				dist[next.second] = next.first;
				pq.push({-next.first, next.second});
			}
		}
	}
	cout << (dist[n - 1] == LONG_MAX ? -1 : dist[n - 1]);
    return 0;    
}