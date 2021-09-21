#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
const int MOD = 1e9 + 7;
ll init(vll &v, vll &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = v[start];
    } else {
        ll mid = (start + end) / 2;
        return tree[node] = init(v, tree, node * 2, start, mid) * init(v, tree, node * 2 + 1, mid + 1, end) % MOD;
    }
}
ll update(vll &tree, int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return tree[node];
    if (start == end) return tree[node] = diff;
    int mid = (start + end) / 2;
    return tree[node] = update(tree, node * 2, start, mid, index, diff) * update(tree, node * 2 + 1, mid + 1, end, index, diff) % MOD;
}
ll mul(vll &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return mul(tree, node * 2, start, mid, left, right) * mul(tree, node * 2 + 1, mid + 1, end, left, right) % MOD;
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vll v(n), tree(4 * n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    init(v, tree, 1, 0, n - 1);
    for (int i = 0; i < m + k; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            v[b - 1] = c;
            update (tree, 1, 0, n - 1, b - 1, c);
        } else {
            cout << mul(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}