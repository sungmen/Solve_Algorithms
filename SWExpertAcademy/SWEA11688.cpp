#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_case; cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        long long l = 1, r = 1;
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') r += l;
            else l += r;
        }
        cout << '#' << tc << ' ' << l << ' ' << r << '\n';
    }
    return 0;
}
