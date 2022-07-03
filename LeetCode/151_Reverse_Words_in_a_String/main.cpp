class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        vector<string> str;
        string tmp = "";
        while (i < s.size()) {
            if (s[i] != ' ') {
                tmp += s[i];
            } else {
                if (tmp != "") str.push_back(tmp);
                tmp = "";
            }
            ++i;
        }
        if (s[i-1] != ' ') {
            str.push_back(tmp);
        }
        string result = "";
        for (i = str.size() - 1; i >= 0; --i) {
            result += str[i];
            if (i) result += " ";
        }
        return result;
    }
};