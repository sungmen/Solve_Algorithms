#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin >> t; t--; ) {
        int p; cin >> p;
        string str1, str2;
        cin >> str1 >> str2;
        int blue = 0, red = 0;
        for (int i = 0; i < str1.size(); i++) {
            if(str1[i]-'0' > str2[i]-'0') red++;
            else if (str1[i]-'0' < str2[i]-'0')blue++;
        }
        if(red > blue) cout << "RED\n";
        else if (red < blue) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }
    return 0;
}