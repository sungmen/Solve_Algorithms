#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int find(int a) {
    if (arr[a] == a) return a;
    else {
        int tmp = find(arr[a]);
        arr[a] = tmp;
        return tmp;
    }
}
void union_arr(int a, int b) {
    int union_a = find(a);
    int union_b = find(b);
    if (union_a == union_b) return;
    arr[union_a] = union_b;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n+1; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x, a, b; cin >> x >> a >> b;
        if (!x) {
            union_arr(a, b);
        } else {
            cout << (find(a)==find(b)?"YES":"NO") << '\n';
        }
    }
    return 0;
}