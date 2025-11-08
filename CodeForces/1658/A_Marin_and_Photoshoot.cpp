#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        int i = 0;
        long long ans = 0;
        while (i < n) {
            if (str[i] == '0') {
                if (i + 1 < n) {
                    if (str[i+1] == '0') {
                        ans += 2;
                        i++;
                    }
                    else {
                        if (i + 2 < n) {
                            if (str[i + 2] == '0') {
                                ans += 1;
                                i+=2;
                            } else {
                                i += 3;
                            }
                        } else {
                            i++;
                        }
                    }
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
