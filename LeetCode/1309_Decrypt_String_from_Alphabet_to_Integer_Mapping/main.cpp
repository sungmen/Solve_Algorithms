class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.size() - 1;
        string str = "";
        while(i >= 0) {
            if (s[i] == '#') {
                int tmp = (s[i-2] - '0') * 10 + (s[i-1] - '0') - 1;
                i -= 3;
                str += (tmp + 'a');
            } else {
                int tmp = (s[i]-'0') - 1;
                i --;
                str += (tmp + 'a');
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};