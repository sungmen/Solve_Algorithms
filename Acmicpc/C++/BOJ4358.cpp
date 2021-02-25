#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str;
    int cnt = 0;
    map <string, double> m;
    while(getline(cin, str)) {
        cnt++;
        if (m.find(str)==m.end()) {
            m[str] = 1;
        } else {
            m.find(str)->second++;
        }        
    }
    cout << fixed;
    cout.precision(4);
    for (map<string, double>::iterator it=m.begin(); it != m.end(); it++) {
        cout << it->first << ' ' << (round(it->second/cnt*100*10000)/10000) << '\n';
    }
    return 0;
}