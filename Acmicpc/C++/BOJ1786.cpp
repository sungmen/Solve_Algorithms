#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int D = 31;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string t, p;
    getline(cin, t);
    getline(cin, p);
    int n = t.size(), m = p.size();
    long h = 1;
    long pHash = 0, nowHash = 0;
    for (int i = 0; i < m; i++) {
        pHash = (pHash * D + p[i]) % MOD;
        nowHash = (nowHash * D + t[i]) % MOD;
        if (i != 0) h = (h * D) % MOD;
    }
    vector<int> v;
    for (int i = 0; i <= n - m; i++) {
        if(nowHash == pHash) v.emplace_back(i + 1);
        nowHash = (D * (nowHash - t[i] * h) + t[i+m]) % MOD;
        if(nowHash < 0) nowHash += MOD;
    }
    cout << v.size() << '\n';
    for (auto i: v) cout << i << ' ';
    return 0;
}