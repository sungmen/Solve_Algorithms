#include <iostream>
#include <map>
using namespace std;
#define endl    '\n'
#define ll      long long

const long mod = (1e+4) + 7;
map <ll, ll> t;

ll tile(int ti) {
    if (t.count(ti))
        return t[ti];
    ll num = ti / 2;
    if (!(ti % 2)) {
        return t[ti] = (tile(num) * tile(num) + tile(num - 1) * tile(num - 1)) % mod;
    } else {
        return t[ti] = (tile(num) * tile(num + 1) + tile(num - 1) * tile(num)) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    t[0] = t[1] = 1;

    int n;
    cin >> n;
    cout << tile(n) << endl;

    return 0;
}
