#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long arr[1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    int j = 2;
    for (int i = 1; i <= 1000; i++) {
        if (i % 2) arr[i] = 0;
        else {
            if (i > 2) {
                arr[i] = (arr[i - 2] * (j * j)) % MOD;
                j ++;
            } else arr[i] = 1;
        }
    }
    while(t--) {
        int n; cin >> n;
        cout << arr[n] << '\n';
    }
    return 0;
}
