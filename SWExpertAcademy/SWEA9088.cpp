/*
* 9088. 다이아몬드 D4
*/
#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int tc=1; tc <= t; tc++) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int s = 0, e = 0, cnt = 0, max_v = 0;
        while (e != n) {
            if(v[e] - v[s] <= k) {
                cnt++, e++;
                if (max_v < cnt) max_v = cnt;
            } else {
                cnt--, s++;
            }
        }
        if(max_v==1)max_v++;
        cout << '#' << tc << ' ' << max_v << '\n';
    }
}