#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s, t; cin >> s >> t;
    while(1) {
        if (s.length() == t.length()) {
            if (s == t) {
                cout << 1;
                return 0;
            }
            break;
        }
        char c = t.back();
        t.pop_back();
        if(c=='B') reverse(t.begin(), t.end());
    }
    cout << 0;
    return 0;
}