#include <bits/stdc++.h>
using namespace std;
int arr[103];
string ans[101];
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    arr[1] = 6;
    arr[2] = 28;
    ans[1] = "255";
    ans[2] = "527";
    for (int i = 3; i < 101; ++i) {
        arr[i] = (((6*arr[i-1] - 4*arr[i-2]))+10000)%1000;
        string str = to_string((arr[i] - 1)%1000);
        if (str.size() == 1) {
            ans[i] = "00" + str;
        } else if (str.size() == 2) {
            ans[i] = "0" + str;
        } else {
            ans[i] = str;
        }
    }
    ans[0] = ans[100];
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        cout << "Case #" << i << ": ";
        if (n == 2) cout << "027\n";
        else cout << ans[n % 100] << '\n';
    }
    return 0;
}