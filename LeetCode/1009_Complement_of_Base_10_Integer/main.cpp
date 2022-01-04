class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        string str = "";
        while(n) {
            str += ((n%2) + '0');
            n /= 2;
        }
        int answer = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i]=='0') answer += (1<<i);
        }
        return answer;
    }
};