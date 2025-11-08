#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t; t--; ) {
        int x, y; cin >> x >> y;
        if(x == y) cout << x+y << '\n';
        else if (x > y) cout << x + (x-1) << '\n';
        else if (y > x) cout << y + (y-1) << '\n';
    }
    return 0;
}