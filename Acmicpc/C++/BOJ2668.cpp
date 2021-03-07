#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n; 
map<int, int> m_all;
void dfs(map<int,int> m, int idx, int start) {
    if (idx == start) {
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            m_all[it->first] = 1;
        }
        return;
    }
    if (m_all.find(v[idx]) != m_all.end()) return;
    if (m.find(v[idx]) != m.end()) return;
    m[v[idx]] = 1;
    dfs(m, v[idx], start);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (m_all.find(i) == m_all.end()) {
            map<int, int> m;
            m[v[i]] = 1;
            dfs(m, v[i], i);
        }
    }
    cout << m_all.size() << '\n';
    for (map<int, int>::iterator it = m_all.begin(); it != m_all.end(); ++it) cout << it->first << '\n';
    return 0;
}