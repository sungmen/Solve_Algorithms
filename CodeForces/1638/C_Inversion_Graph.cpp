#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, res = 0; cin >> n;
        long long sum = 0;
        for (long long i = 1; i <= n; i++) {
            long long num; cin >> num;
            sum += num;
            if (sum == ((i)*(i+1))/2) res++;
        }   
        cout << res << '\n';
    }
    return 0;
}
