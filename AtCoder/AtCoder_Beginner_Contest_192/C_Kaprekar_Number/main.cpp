#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n, k; cin >> n >> k;
    while(k--) {
        string str = to_string(n);
        string str_2 = to_string(n);
        sort(str.begin(), str.end());
        sort(str_2.begin(), str_2.end(), greater<char>());
        int n1 = stoi(str);
        int n2 = stoi(str_2);
        n = n2 - n1;
        if (!n) {
            cout << 0;
            return 0;
        }
    }
    cout << n;
    return 0;
}