class Solution {
public:
    string reverseWords(string s) {
        size_t pos = 0;
        string token;
        string res = "";
        while ((pos = s.find(" ")) != string::npos) {
            token = s.substr(0, pos);
            reverse(token.begin(), token.end());
            res += (token + " ");
            s.erase(0, pos + 1);
        }
        reverse(s.begin(), s.end());
        res += s;
        return res;
    }
};