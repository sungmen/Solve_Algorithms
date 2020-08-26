#include <bits/stdc++.h>
using namespace std;
long long ans;
long long last;
vector<pair<long long, long long>> arr [100001];
void bfs(vector<bool>& chk) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push(pair<long long, long long>(0, 1));
    while (!pq.empty()) {
        pair<long long, long long> cur = pq.top();
        pq.pop();
        if (chk[cur.second]) continue;
        chk[cur.second] = true;
        ans += cur.first;
        if(last < cur.first) last = cur.first;
        for (int i = 0; i < arr[cur.second].size(); i++) {
            if (!chk[arr[cur.second][i].second]) {
                pq.push(arr[cur.second][i]);
            }
        }
    }
    return;
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<bool> chk(v+1, false);
    for(int i = 0; i < e; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        arr[a].emplace_back(make_pair(c, b));
        arr[b].emplace_back(make_pair(c, a));
    }
    last = 0;
    bfs(chk);
    cout << ans - last;
    return 0;
}