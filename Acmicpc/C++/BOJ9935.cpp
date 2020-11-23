#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
char res[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str1, str2; cin >> str1 >> str2;
    char chr = str2[str2.size()-1];
    reverse(str2.begin(), str2.end());
    int len = 0;
    for (char &c : str1) {
        if (c == chr) {
            int cnt = 0;
            for (int i = 1; i < str2.size(); i++) {
                if (res[len-i] == str2[i]) cnt++;
                else break;
            }
            if (cnt == str2.size()-1) {
                len -= str2.size()-1;
            } else {
                res[len++] = c;
            }
        } else {
            res[len++] = c;
        }
    }
    if(len) {
        for (int i = 0; i < len; i++) {
            cout << res[i];
        }
    }
    else cout << "FRULA";
    return 0;
}