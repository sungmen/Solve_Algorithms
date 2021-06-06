#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int arr[10001];
        memset(arr, 0, sizeof(arr));
        int n; cin >> n;
        n--;
        while(n--) {
            int a, b; cin >> a >> b;
            arr[b] = a;
        }
        int r1, r2; cin >> r1 >> r2;
        unordered_map<int, int> m;
        while (r1 != 0) {
            m[r1] = 1;
            r1 = arr[r1];
        }
        while (r2 != 0) {
            if (m[r2]) break;
            r2 = arr[r2];
        }
        cout << r2 << '\n';
    }
    return 0;
}