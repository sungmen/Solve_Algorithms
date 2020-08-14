#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    for(cin >> t; t--;) {
        vector<int> v;
        string str;
        cin >> str;
        int cnt = 0;
        for(int i = 0; i <= str.size(); i++) {
            if (i == str.size()) {
                if(cnt)
                    v.emplace_back(cnt);
                cnt = 0;
                sort(v.begin(), v.end());
                for(int i = v.size() - 1; i >= 0; i -= 2) {
                    cnt += v[i];
                }
                cout << cnt << '\n';
                break;
            } else {
                if(str[i] == '1') {
                    cnt++;
                } else {
                    if (cnt) {
                        v.emplace_back(cnt);
                    }
                    cnt = 0;
                }
            }
        }
    }
    
    return 0;
}