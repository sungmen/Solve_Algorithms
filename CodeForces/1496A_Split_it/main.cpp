#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        if (k == 0) {
            cout << "YES\n";
            continue;
        }
        if (k == (double)n/2) {
            cout << "NO\n";
            continue;
        }
        string tmp = str.substr(n-k, k);
        reverse(tmp.begin(), tmp.end());
        if (str.substr(0,k).compare(tmp) == 0) {
            cout << "YES\n";
        } else  {
            cout << "NO\n";
        }
    }
    return 0;
}