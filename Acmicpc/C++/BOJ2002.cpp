#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, res = 0; cin >> n;
    map<string, int> p;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        p[str] = i;
    }
    string cmp[n];
    for (int i = 0; i < n; i++) cin >> cmp[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[cmp[i]] > p[cmp[j]]) {
                res++;
                break;
            }
        }
    }
    cout << res;
    return 0;
}