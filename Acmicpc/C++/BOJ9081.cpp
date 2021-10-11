#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    int t; cin >> t;
    while(t--) {
        string s, p, o; cin >> s;
        p = o = s;
        sort(p.begin(), p.end());
        next_permutation(s.begin(), s.end());
        if (! p.compare(s)) {
            cout << o << '\n';
        } else {
            cout << s << '\n';
        }
    }
    return 0;
}