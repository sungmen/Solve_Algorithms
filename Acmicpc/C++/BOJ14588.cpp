#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int d[301][301];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second.first;
        v[i].second.second = i;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF;
    for (int i = 0; i < n; i++) d[i][i] = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i +1; j < n; j++) {
            if(v[i].second.first >= v[j].first) {
                d[v[i].second.second][v[j].second.second] = 1;
                d[v[j].second.second][v[i].second.second] = 1;
            }
            else break;
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if(d[a-1][b-1] == INF || d[a-1][b-1] == 0) cout << -1 << '\n';
        else cout << d[a-1][b-1] << '\n';
        
    }
    return 0;
}