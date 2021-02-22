#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    regex re("(100+1+|01)+");
    int n; cin >> n;
    while(n--) {
        string str; cin >> str; 
        cout << (regex_match(str, re)?"YES" : "NO") << '\n';
    }
    return 0;
}