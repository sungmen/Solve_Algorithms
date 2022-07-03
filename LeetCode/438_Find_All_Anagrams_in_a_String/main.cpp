class Solution {
private:
    int stand[26];
    int alp[26];
    int c = 0;
    bool chk[26];
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        for (auto q : p) {
            if (!stand[q-'a']) {
                c++;
                chk[q-'a'] = 1;
            }
            stand[q-'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i >= p.size()) {
                alp[s[i-p.size()]-'a']--;
                if (!chk[s[i-p.size()]-'a'] && stand[s[i-p.size()]-'a'] != alp[s[i-p.size()]-'a']) {
                    c++;
                    chk[s[i-p.size()]-'a'] = 1;
                } else if (chk[s[i-p.size()]-'a'] && stand[s[i-p.size()]-'a'] == alp[s[i-p.size()]-'a']){
                    c--;
                    chk[s[i-p.size()]-'a'] = 0;
                }
            }
            alp[s[i]-'a']++;
            if (!chk[s[i]-'a'] && stand[s[i]-'a'] != alp[s[i]-'a']) {
                c++;
                chk[s[i]-'a'] = 1;
            } else if (chk[s[i]-'a'] && stand[s[i]-'a'] == alp[s[i]-'a']){
                c--;
                chk[s[i]-'a'] = 0;
            }
            if (!c) res.push_back(i - p.size()+1);
        }
        return res;
    }
};