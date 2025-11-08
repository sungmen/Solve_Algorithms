#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        int n;cin>>n;
        string str;cin>>str;
        int z = 0, o = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i]=='0') z++;
            else o++;
        }
        string ans = "";
        if(z > o) {
            for(int i = 0; i < n; i++) {
                ans += '0';
            }
        } else {
            for(int i = 0; i < n; i++) {
                ans += '1';
            }
        }
        cout << ans << '\n';
    }
}