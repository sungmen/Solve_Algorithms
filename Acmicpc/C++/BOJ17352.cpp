#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 3e5+1;
int ds[MAX];
void init_set() {
    for (int i = 0; i < MAX; i++) ds[i] = i;
}
int find_set(int a) {
    if (ds[a] == a) return a;
    else {
        int tmp = find_set(ds[a]);
        ds[a] = tmp;
        return tmp;
    }
}
void join_set(int a, int b) {
    int tmp_a = find_set(a);
    int tmp_b = find_set(b);
    if (tmp_a == tmp_b) return;
    else {
        ds[tmp_b] = tmp_a;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    init_set();
    for (int i = 0; i < n-2; i++) {
        int a, b; cin >> a >> b;
        join_set(a, b);
    }
    int tmp_a = find_set(1);
    for (int i = n; i >= 2; i--) {
        if (tmp_a != find_set(i)) {
            cout << 1 << ' ' << i;
            return 0;
        }
    }
    
    return 0;
}