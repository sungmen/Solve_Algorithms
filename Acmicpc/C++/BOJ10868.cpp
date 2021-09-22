#include <bits/stdc++.h>
using namespace std;
int init(vector<int> &v, vector<int> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    else {
        int mid = (start + end) / 2;
        return tree[node] = min(init(v, tree, node * 2, start, mid), init(v, tree, node * 2 + 1, mid + 1, end));
    }
}
int find(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1e9 + 1;
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(find(tree, node * 2, start, mid, left, right), find(tree, node * 2 + 1, mid + 1, end, left, right));
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n), tree(4 * n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    init(v, tree, 1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        cout << find(tree, 1, 0, n - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}