#include <bits/stdc++.h>
using namespace std;
pair<int, int> init(vector<int> &v, vector<pair<int,int>> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = {v[start], v[start]};
    else {
        int mid = (start + end) / 2;
        pair<int, int> f = init(v, tree, node * 2, start, mid), s = init(v, tree, node * 2 + 1, mid + 1, end);
        return tree[node] = {min(f.first, s.first), max(f.second, s.second)};
    }
}
pair<int, int> find(vector<pair<int,int>> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return {1e9 + 1, 0};
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    pair<int, int> f = find(tree, node * 2, start, mid, left, right), s = find(tree, node * 2 + 1, mid + 1, end, left, right);
    return {min(f.first, s.first), max(f.second, s.second)};
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<pair<int,int>> tree(4 * n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    init(v, tree, 1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        pair<int, int> r = find(tree, 1, 0, n - 1, a - 1, b - 1);
        cout << r.first << ' ' << r.second << '\n';
    }
    return 0;
}