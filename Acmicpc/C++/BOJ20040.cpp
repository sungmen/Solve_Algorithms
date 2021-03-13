#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5+1;
int arr[MAX];
void set_union() {
    for (int i = 0; i < MAX; i++) arr[i] = i;
}
int find(int a) {
    if (arr[a] == a) return a;
    else {
        int tmp = find(arr[a]);
        arr[a] = tmp;
        return tmp;
    }
}
bool union_(int a, int b) {
    int union_a = find(a);
    int union_b = find(b);
    if (union_a == union_b) return true;
    arr[union_a] = union_b;
    return false;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    set_union();
    int n, m; cin >> n >> m;
    for (int i = 0; i < m ; i++) {
        int a, b; cin >> a >> b;
        if (union_(a, b)) {
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}