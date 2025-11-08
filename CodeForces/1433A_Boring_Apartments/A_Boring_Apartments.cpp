#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    int d[4] = {1, 3, 6, 10};
    for(cin >> t; t--;) {
        string str; cin >> str;
        int p = stoi(str) % 10;
        cout << (((p-1) * 10) + d[str.size()-1]) << '\n';
    }
    return 0;
}