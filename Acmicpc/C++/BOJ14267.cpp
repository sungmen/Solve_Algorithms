#include <bits/stdc++.h>
using namespace std;
#define MAX 1e5 + 1
vector<vector<int>> v(MAX);
vector<int> answer(MAX);
int main() {
    //reopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        if (i != 1) {
            v[a].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        answer[a] += b;
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(! q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur.first].size(); ++i) {
            answer[v[cur.first][i]] += cur.second;
            q.push({v[cur.first][i], answer[v[cur.first][i]]});
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << answer[i] << ' ';
    }
    return 0;
}
