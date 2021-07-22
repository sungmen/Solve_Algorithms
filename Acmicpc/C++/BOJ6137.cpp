#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        char t; cin >> t;
        s += t;
    }
    int l = 0, r = s.size() - 1;
    string res = "";
    while (l <= r) {
        if (s[l] > s[r]) {
            res += s[r--];
        } else if (s[l] < s[r]) {
            res += s[l++];
        } else {
            int tmpL = l, tmpR = r, tmp = 1;
            while (s[tmpL] == s[tmpR]) {
                if (tmpR > 0) tmpR--;
                if (tmpL < n) tmpL++;
                if (s[tmpL] < s[tmpR]) tmp = 1;
                else if (s[tmpL] > s[tmpR]) tmp = 0;
            }
            if (tmp) {
                res += s[l++];
            } else {
                res += s[r--];
            }
        }
    }
    int t = n / 80;
    int tr = n % 80;
    if (tr) t++;
    int i = 0;
    for (i = 0; i < t - 1; i++) {
        cout << res.substr(i*80, 80) << '\n';
    }
    cout << res.substr(i * 80);
    return 0;
}