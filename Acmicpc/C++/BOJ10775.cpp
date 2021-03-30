#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
void set_union(int g) {
    for (int i = 1; i <= g; i++) arr[i] = i;
}
int fnd_union(int a) {
    if (arr[a] == a) return a;
    else {
        int tmp = fnd_union(arr[a]);
        arr[a] = tmp;
        return tmp;
    }
}
void merge_set(int a, int b) {
    int fnd_a = fnd_union(a);
    int fnd_b = fnd_union(b);
    arr[fnd_a] = fnd_b;
    
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int g, p; cin >> g >> p;
    set_union(g);
    int cnt = 0;
    for (int i = 1; i <= p; i++) {
        int air; cin >> air;
        int tmp = fnd_union(air);
        if (tmp) {
            merge_set(tmp, tmp-1);
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt;
    return 0;
}