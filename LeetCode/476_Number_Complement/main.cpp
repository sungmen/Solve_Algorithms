class Solution {
public:
    int findComplement(int num) {
        string tmp = "";
        while(num) {
            if (num&1) tmp += '0';
            else tmp += '1';
            num >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        int answer = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == '1') {
                answer += (1 << (tmp.size() - i - 1));
            }
        }
        return answer;
    }
};