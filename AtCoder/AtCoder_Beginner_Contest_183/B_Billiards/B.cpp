#include <bits/stdc++.h>
using namespace std;
int main() {
    long double sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
    cout << fixed;
    cout << setprecision(10);
    long double x = gx - sx, y = gy + sy, mid = y / x, res = sy / mid;
    cout << res + sx;
    return 0;
}