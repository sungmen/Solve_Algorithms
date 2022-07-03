/**
* Runtime: 28 ms, faster than 20.91% of C++ online submissions for Basic Calculator II.
* Memory Usage: 13.1 MB, less than 9.98% of C++ online submissions for Basic Calculator II.
*/

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<string> str;
        str.push("");
        int i = 0;
        while (i < s.size()) {
            if(s[i] == ' ') {
                i++;
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                str.top() += s[i++];
            } else if (s[i] =='+') {
                str.push("");
                i++;
            } else if(s[i] == '-') {
                str.push("-");
                i++;
            } else if (s[i] == '*') {
                string tmp = "";
                i++;
                while(s[i] == ' ') i++;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    tmp += s[i++];
                }
                if(!str.empty()) {
                    int t1 = stoi(str.top());
                    int t2 = stoi(tmp);
                    str.top() = to_string(t1 * t2);
                }
            } else if (s[i] == '/') {
                string tmp = "";
                i++;
                while(s[i] == ' ') i++;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9' ) {
                    tmp += s[i++];
                }
                if(!str.empty()) {
                    int t1 = stoi(str.top());
                    int t2 = stoi(tmp);
                    str.top() = to_string(t1 / t2);
                }
            }
        }
        while(!str.empty()) {
            ans += stoi(str.top());
            str.pop();
        }
        return ans;
    }
};