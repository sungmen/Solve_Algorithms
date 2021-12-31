class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> sets;
        string t = "";
        for (int i = 0; i < 10; ++i) {
            t += s[i];
        }
        sets[t] = 1;
        vector<string> answer;
        for (int i = 10; i < s.size(); ++i) {
            t.erase(t.begin());
            t += s[i];
            sets[t]++;
            if (sets[t] == 2) answer.push_back(t);
        }
        return answer;
    }
};