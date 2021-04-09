#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[MAX];
int rrr[MAX];
void init_set() {
    for (int i = 0; i < MAX; i++) {
        arr[i] = i;
        rrr[i] = i+1;
    }
    rrr[MAX-1] = -1;
}
int find_union(int x) {
    if (x == arr[x]) return x;
    else {
        int tmp = find_union(arr[x]);
        arr[x] = tmp;
        return tmp;
    }
}
void merge_set(int x, int y) {
    int fnd_x = find_union(x);
    int fnd_y = find_union(y);
    if (fnd_x == fnd_y) return;
    else arr[fnd_x] = fnd_y;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    init_set();
    int n, m; cin >> n >> m;
    int ans = n;
    while (m--) {
        int x, y; cin >> x >> y;
        while(find_union(x) != find_union(y)) {
            ans--;
            rrr[x] = rrr[find_union(x)];
            merge_set(x, y);
            x = rrr[x];
        }
    }
    cout << ans;
    return 0;
}
