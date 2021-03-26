#include <bits/stdc++.h>
using namespace std;
int arr[201];
void set_union() {
    for (int i = 0; i <= 200; i++) {
        arr[i] = i;
    }
}
int fnd_union(int a) {
    if (arr[a] == a) return a;
    else {
        int tmp = fnd_union(arr[a]);
        arr[a] = tmp;
        return tmp;
    }
}
void conn(int a, int b) {
    int fnd_a = fnd_union(a);
    int fnd_b = fnd_union(b);
    if (fnd_a == fnd_b) return;
    else arr[fnd_a] = fnd_b;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    set_union();
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            if (c) {
                conn(i, j);
            }
        }
    }
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        v[i] = c-1;
    }
    if (m == 1) cout << "YES";
    else {
        bool chk = true;
        for (int i = 0; i < m - 1; i++) {
            if (fnd_union(v[i]) != fnd_union(v[i+1])) {
                chk = false;
            }
        }
        cout << (chk ? "YES" : "NO");
    }

    return 0;
}