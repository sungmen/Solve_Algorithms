#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int D = 31;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string t; cin >> t;
    int t_size = t.size();
    string text = "";
    for (int i = 0; i < t_size; i++) {
        if (!(t[i] >= '0' && t[i] <= '9')) {
            text += t[i];
        }
    }
    int text_size = text.size();
    string pattern;
    cin >> pattern;
    int pattern_size = pattern.size();
    if (text_size < pattern_size) {
        cout << 0;
    } else {
        long h = 1;
        long pattern_Hash = 0, now_Hash = 0;
        for (int i = 0; i < pattern_size; i++) {
            pattern_Hash = (pattern_Hash * D + pattern[i]) % MOD;
            now_Hash = (now_Hash * D + text[i]) % MOD;
            if (i != 0) h = (h * D) % MOD;
        }
        for (int i = 0; i <= text_size - pattern_size; i++) {
            if (now_Hash == pattern_Hash) {
                cout << 1;
                return 0;
            }
            now_Hash = (D * (now_Hash - text[i] * h) + text[i + pattern_size]) % MOD;
            if (now_Hash < 0) now_Hash += MOD;
        }
        cout << 0;
    }
    return 0;
}