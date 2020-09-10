#include <bits/stdc++.h>
using namespace std;
string decToBinary(int n) {
    string str = "";
    for (int i = 30; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) str += "1";
        else str += "0";
    }
    return str;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, m; cin >> n >> m;
        string str = decToBinary(m);
        int chk = 1;
        for (int i = str.size()-1; i > str.size()-1-n; i--) {
            if(str[i] == '0') {
                chk = 0;
                break;
            }
        }
        cout << '#' << tc << ' ';
        if(chk) cout << "ON\n";
        else cout << "OFF\n";
    }
    return 0;
}