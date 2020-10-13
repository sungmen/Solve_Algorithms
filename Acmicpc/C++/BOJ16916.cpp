#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int D = 31;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string text, pattern;
    cin >> text >> pattern;
    int textSize = text.size(), patternSize = pattern.size();
    long h = 1;
    long patternHash = 0, nowHash = 0;
    for (int i = 0; i < patternSize; i++) {
        patternHash = (patternHash * D + pattern[i]) % MOD;
        nowHash = (nowHash * D + text[i]) % MOD;
        if (i != 0) h = (h * D) % MOD;
    }
    for (int i = 0; i <= textSize - patternSize; i++) {
        if (nowHash == patternHash) {
            cout << 1;
            return 0;
        }
        nowHash = (D * (nowHash - text[i] * h) + text[i+patternSize]) % MOD;
        if(nowHash < 0) nowHash += MOD;
    }
    cout << 0;
}