#include <bits/stdc++.h>
using namespace std;
const int SIZE = 3001;
int DP[SIZE][SIZE];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;
    memset(DP, 0, sizeof(DP));
    for (int i = 3; i <= str1.size(); i+=3) {
        for (int j = 3; j <= str2. size(); j+=3) {
            if(!(str1.substr(i - 3, 3).compare(str2.substr(j - 3, 3)))) {
                DP[i][j] = 1 + DP[i-3][j-3];
            } else {
                DP[i][j] = max(DP[i][j-3], DP[i-3][j]);
            }
        }
    }
    cout << DP[str1.size()][str2.size()];
    return 0;
}