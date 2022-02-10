#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string w;
        int k;
        cin >> w >> k;
        vector<vector<int>> v(26);
        int minlen = 10001, maxlen = 0;
        for (int i = 0; i < w.size(); i++) {
            v[w[i]-'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            if (v[i].size() >= k) {
                for (int j = 0; j <= v[i].size() - k; j++) {
                    minlen = min(minlen, v[i][j+k-1]-v[i][j]+1);
                    maxlen = max(maxlen, v[i][j+k-1]-v[i][j]+1);
                }
            }
        }
        if (!maxlen) cout << -1 << '\n';
        else cout << minlen << ' ' << maxlen << '\n';
    }
    return 0;
}