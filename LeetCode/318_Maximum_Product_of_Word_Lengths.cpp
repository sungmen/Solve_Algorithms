class Solution {
public:
    int maxProduct(vector<string>& words) {
        int answer = 0;
        vector<bitset<26>> v(words.size());
        // words to bitset<26> 
        // in vector
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                v[i][words[i][j]-'a'] = 1;
            }
        }
        // set bitset, use or bitmask, check none(), if all 0 compaere answer
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if((v[i]&v[j]).none() && answer < words[i].size() * words[j].size()) {
                    answer = words[i].size() * words[j].size();
                }
            }
        }
        return answer;
    }
};