#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, x, t;
    cin >> n >> x >> t;
    int res = n / x;
    if (n % x) res++;
    cout << res * t;
}