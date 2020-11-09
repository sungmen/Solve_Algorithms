#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int SIZE = 4e3 + 1;
int DP[SIZE][SIZE];
int LCS(string str1, string str2) {
    int result = 0;
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
                result = max(result, DP[i][j]);
            } 
        }
    }
    return result;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str1, str2; cin >> str1 >> str2;
    memset(DP, 0, sizeof(DP));
    cout << LCS(str1, str2) << '\n';
    return 0;
}