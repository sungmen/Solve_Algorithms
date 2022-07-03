/*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Strings.
    Memory Usage: 7 MB, less than 71.49% of C++ online submissions for Add Strings.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int upper = 0;
        string res = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i >= 0 && j >= 0) {
            int temp = (num1[i--] - '0') + (num2[j--] - '0') + upper;
            upper = temp / 10;
            temp %= 10;
            res += (temp + '0');
        }
        if (i == -1) {
            while(j >= 0) {
                int temp = (num2[j--] - '0') + upper;
                upper = temp / 10;
                temp %= 10;
                res += (temp + '0');
            }
        } else if (j == -1) {
            while(i >= 0) {
                int temp = (num1[i--] - '0') + upper;
                upper = temp / 10;
                temp %= 10;
                res += (temp + '0');
            }
        }
        if(upper) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};