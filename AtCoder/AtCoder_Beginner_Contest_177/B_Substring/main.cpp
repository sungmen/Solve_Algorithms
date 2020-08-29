#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s, t;cin>>s>>t;
    int slen = s.size();
    int tlen = t.size();
    int max_v = 0;
    for (int i = 0; i < slen - tlen + 1; i++) {
        string k = s.substr(i, tlen);
        int cnt = 0;
        for(int j = 0; j < tlen; j++) {
            if(k[j] == t[j]) cnt++;
        }
        if(max_v < cnt) max_v = cnt;
    }
    cout << tlen - max_v;
}
