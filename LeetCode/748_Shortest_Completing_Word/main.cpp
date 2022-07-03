class Solution {
private:
    int alp[26];
    int chr[26];
    int len = INT_MAX;
    string result = "";
    
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        for (auto s : licensePlate) {
            if (s >= 'a' && s <= 'z') {
                alp[s-'a'] ++;
            } else if (s >= 'A' && s <= 'Z') {
                alp[s-'A'] ++;
            }
        }
        for (auto word : words) {
            memset(chr, 0, sizeof(chr));
            for (auto w : word) {
                chr[w-'a'] ++;
            }
            bool chk = 1;
            for (int i = 0; i < 26; ++i) {
                if (alp[i] > chr[i]) {
                    chk = 0;
                    break;
                }
            }
            if (!chk) continue;
            if (word.size() < len) {
                len = word.size();
                result = word;
            }
        }
        return result;
    }
};