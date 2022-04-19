class Solution {
public:
    int minimumSum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        // sort string number ascending
        // input four digit number
        // str[0]str[2], str[1]str[3] is minimum sum
        int t1 = (str[0] - '0') * 10 + str[2] - '0';
        int t2 = (str[1] - '0') * 10 + str[3] - '0';
        return t1 + t2;
    }
};