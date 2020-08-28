#include <iostream>
#include <vector>
using namespace std;
int res[1001][1001];
int32_t main() {
    string str1, str2; cin >> str1 >> str2;
    int i, j;
    for (i = 1; i <= str1.size(); i++) {
        for (j = 1; j <= str2.size(); j++) {
            if (str1[i-1] == str2[j-1]) {
                res[i][j] = res[i-1][j-1] + 1;
            } else {
                if(res[i-1][j] > res[i][j-1]) {
                    res[i][j] = res[i-1][j];
                } else {
                    res[i][j] = res[i][j-1];
                }
            }
        }
    }
    cout << res[str1.size()][str2.size()] << '\n';
    i = str1.size(); j = str2.size();
    vector<char> v;
    while (i >= 1 && j >= 1) {
        if (res[i][j] == res[i - 1][j]) i--;
        else if (res[i][j] == res[i][j - 1]) j--;
        else {
            v.emplace_back(str1[i-1]);
            i--;
            j--;
        }
    }
    for (i = v.size() - 1; i >= 0; i--) cout << v[i];

    return 0;
}