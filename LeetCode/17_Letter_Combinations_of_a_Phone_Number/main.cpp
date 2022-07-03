class Solution {
private:
    string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        vector<string> tmp;
        for (int i = 0; i < arr[digits[0]-'0'].size(); i++) {
            string t;
            t.push_back(arr[digits[0]-'0'][i]);
            tmp.push_back(t);
        }
        for (int i = 1; i < digits.size(); i++) {
            vector<string> tmp2 = tmp;
            tmp.clear();
            for(int k = 0; k < tmp2.size(); k++) {
                for (int j = 0;j < arr[digits[i]-'0'].size(); j++) {
                    tmp.push_back(tmp2[k] + arr[digits[i]-'0'][j]);
                }
            }
        }
        return tmp;
    }
};