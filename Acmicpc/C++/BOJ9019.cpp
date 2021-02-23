#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e4;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        vector<bool> chk(10000, false);
        queue<pair<int, string>> q;
        q.push({a, ""});
        chk[a]=true;
        while (!q.empty()) {
            pair<int, string> cur = q.front();
            q.pop();
            if (cur.first == b) {
                cout << cur.second << '\n';
                break;
            }
            int tmp = 0;
            // D
            tmp = (cur.first*2)%MOD;
            if (!chk[tmp]) {
                q.push({tmp, cur.second+"D"});
                chk[tmp] = true;
            }            
            // S
            tmp = cur.first-1;
            if (tmp<0) tmp = 9999;
            if (!chk[tmp]) {
                q.push({tmp, cur.second+"S"});
                chk[tmp] = true;
            }            
            // L
            tmp = (cur.first%1000)*10+cur.first/1000;
            if (!chk[tmp]) {  
                q.push({tmp, cur.second+"L"});
                chk[tmp] = true;            
            }            
            //R
            tmp = (cur.first%10)*1000+(cur.first/10);
            if (!chk[tmp]) {
                q.push({tmp, cur.second+"R"});
                chk[tmp] = true;            
            }            
        }
    }
    return 0;
}