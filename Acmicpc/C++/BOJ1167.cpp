#include <bits/stdc++.h>
using namespace std;
map<int, int> m[100001];
int p=1;
int MAX = 0;
void dfs(int idx, vector<bool> chk, int sum) {
    if (MAX < sum) {
        p = idx;
        MAX = sum;
    }
    for(map<int,int>::iterator it = m[idx].begin(); it != m[idx].end(); ++it) {
        if(chk[it->first]) continue;
        chk[it->first] = true;
        dfs(it->first, chk, sum+(it->second));
        chk[it->first] = false;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int v; cin >> v;
    for (int i = 1; i <= v; i++) {
        int v_; cin >> v_;
        while(1) {
            int n_; cin >> n_;
            if (n_ == -1) break;
            int val_; cin >> val_;
            if (m[v_].find(n_) == m[v_].end()) {
                m[v_][n_] = val_;
            }
            if (m[n_].find(v_) == m[n_].end()) {
                m[n_][v_] = val_;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        vector<bool> chk(v+1, false);
        chk[p] = true;
        dfs(p, chk, 0);
    }
    cout << MAX;
    return 0;
}