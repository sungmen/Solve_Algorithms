class Solution {
public:
    int longestDecomposition(string text) {
        int l = 0, r = text.size() - 1, res = 0;
        string strl = "", strr = "";
        while (l < r) {
            strl = (strl + text[l++]);
            strr = (text[r--] + strr);
            if (!strl.compare(strr)) {
                res += 2;
                strl = "";
                strr = "";
            }            
        }
        if (strl.size() > 0) {
            ++res;
        } else if (text.size() % 2) {
            ++res;
        }
        return res;
    }
};