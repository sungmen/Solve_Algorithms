/**
* Runtime: 100 ms, faster than 25.00% of C++ online submissions for Count Items Matching a Rule.
* Memory Usage: 36.7 MB, less than 25.00% of C++ online submissions for Count Items Matching a Rule.
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> m[3];
        for (auto i : items) {
            for (int j = 0; j < 3; j++) {
                if(m[j].find(i[j])==m[j].end()) {
                    m[j][i[j]] = 1;
                } else {
                    m[j].find(i[j])->second++;
                }                
            }
        }
        switch(ruleKey[0]) {
            case 't':
                if (m[0].find(ruleValue) == m[0].end()) return 0;
                else return m[0].find(ruleValue)->second;
                break;
            case 'c':
                if (m[1].find(ruleValue) == m[1].end()) return 0;
                else return m[1].find(ruleValue)->second;                
                break;
            case 'n':
                if (m[2].find(ruleValue) == m[2].end()) return 0;
                else return m[2].find(ruleValue)->second;
                break;
        }
        return 0;
    }
};