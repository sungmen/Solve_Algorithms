#include <bits/stdc++.h>
using namespace std;
vector<pair<double, int>> v[101];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    pair<double, double> pd[n];
    bool chk[n];
    memset(chk, false, sizeof(chk));
    for (int i = 0; i < n; i++) cin >> pd[i].first >> pd[i].second;
    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            double tmp = sqrt(((pd[i].first - pd[j].first) * (pd[i].first - pd[j].first)) + ((pd[i].second - pd[j].second) * (pd[i].second - pd[j].second)));
            v[i].emplace_back(make_pair(tmp, j));
            v[j].emplace_back(make_pair(tmp, i));
        }
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push(pair<double, int> (0.0, 0));
    double ans = 0.0; 
    while (!pq.empty()) {
        pair<double, int> cur = pq.top();
        pq.pop();
        if (chk[cur.second]) continue;
        else chk[cur.second] = true;
        ans += cur.first;
        for (int i = 0; i < v[cur.second].size(); i++) if (!chk[v[cur.second][i].second]) pq.push(v[cur.second][i]);
    }
    cout << ans;
    return 0;
}