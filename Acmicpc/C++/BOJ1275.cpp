#include <bits/stdc++.h>
using namespace std;
long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = v[start];
    else return tree[node] = init(v, tree, node * 2, start, (start + end) / 2) + init(v, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (end < left || start > right) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum (tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(vector<long long> & tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<long long> v(n), tree(4 * n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    init(v, tree, 1, 0, n - 1);
    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);
        cout << sum (tree, 1, 0, n - 1, a - 1, b - 1) << '\n';
        long long diff = d - v[c - 1];
        v[c - 1] = d;
        update(tree, 1, 0, n - 1, c - 1, diff);
    }
    return 0;    
}