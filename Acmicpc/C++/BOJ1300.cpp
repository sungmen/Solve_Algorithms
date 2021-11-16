#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool smaller(long long mid) {
    long long chk = 0;
    for (int i = 1; i <= n; ++i) {
        chk += min(n, mid / i);
    }
    return chk >= k;
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    long  l = 0, r = n * n;
    while (l < r) {
        long long mid = ((r - l) / 2) + l;
        if (smaller(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }    
    cout << l;
    return 0;
}
