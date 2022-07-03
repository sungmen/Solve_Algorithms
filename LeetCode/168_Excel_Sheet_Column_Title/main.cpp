class Solution {
public:
    string convertToTitle(int n) {
        string str = "";
        while (n != 0) {
            n--;
            str += char((n % 26) + 'A');
            n /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};