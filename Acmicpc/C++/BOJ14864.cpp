#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int chk[MAX];
int n, m; 
void init(int n) {
    for (int i = 1; i <= n; i++) arr[i] = i;
}
void ord(int m) {
    while(m--) {
        int x, y; cin >> x >> y;
        arr[x]++;
        arr[y]--;
    }
}
bool check() {
    for (int i = 1; i <= n; i++) {
        if (chk[arr[i]]) {
            return false;
        } else {
            chk[arr[i]]++;
        }
    }
    return true;
}
void res(bool b) {
    if (b) {
        for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    } else {
        cout << -1;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    init(n);
    ord(m);
    res(check());
    return 0;
}