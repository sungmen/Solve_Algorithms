#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin >> t; t--;) {
        long long n, x; cin >> n >> x;
        queue<pair<long long, long long>> q;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            q.push({a, 1});
        }
        long long sum = 0;
        bool chk = true;
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            sum += (cur.first * cur.second);
            if (!(cur.first % x) && chk) {
                int tmp = cur.first / (double)x;
                q.push({tmp, x * cur.second});
            } else {
                chk = false;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}