class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        
        for (auto ma : magazine) {
            cnt[ma - 'a'] ++;
        }
        
        for (auto ra : ransomNote) {
            cnt[ra - 'a'] --;
            if (cnt[ra - 'a'] < 0) return false;
        }
        
        return true;
    }
};