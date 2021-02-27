#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n; cin >> n;
    long long t = 2;
    long long p = 2;
    long long ans = n;
    map<long long, int> m; 
    while(true) {
        if (m.find(long(pow(t,p))) == m.end()) {
            m[long(pow(t,p))] = 1;
            if (long(pow(t,p)) <= n) {
                ans--;
                p++;
            } else {
                t++;
                p=2;
            }
        } else {
            if (long(pow(t,p)) <= n) {
                p++;
            } else {
                t++;
                p=2;
            }

        }
        if (t > n || p > n) break;
        if (p == 2 && long(pow(t,p))  > n) break;
    }
    cout << ans;
    return 0;
}