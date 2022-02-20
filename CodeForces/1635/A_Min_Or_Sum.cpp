#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        long long a; cin >> a;
        long long t = a;
        for (int i = 1; i < n; i++) {
            cin >> a;
            t = t | a;
        }
        cout << t << '\n';
    }
    return 0;
}
