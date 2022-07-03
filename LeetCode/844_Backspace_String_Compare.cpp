class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "", str2 = "";
        for (auto c : s) {
            if (c=='#' && str1.size()) {
                str1.pop_back();
            } else if (c != '#') {
                str1 += c;
            }
        }
        for (auto c: t) {
            if (c=='#' && str2.size()) {
                str2.pop_back();
            } else if (c != '#') {
                str2 += c;
            }
        }
        return (str1 == str2);
    }
};