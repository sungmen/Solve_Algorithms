#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        int n; cin >> n;
        vector<int> vc(26, 0);
        string str;
        for(int i = 0; i < n; i++) {
            cin >> str;
            for(int j = 0;j < str.size(); j++) {
                vc[str[j]-'a']++;
            }
        }
        bool chk = true;
        for(int i = 0; i < 26; i++) {
            if(vc[i] % n != 0) {
                chk = false;
                break;
            }
        }
        if (chk) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        
    }
}
