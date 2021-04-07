class Solution {
public:
    int countString(string str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            switch (str[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    cnt++;
                    break;
            }
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        string f = s.substr(0, s.size()/2);
        string n = s.substr(s.size()/2, s.size());
        return countString(f) == countString(n);
    }
};