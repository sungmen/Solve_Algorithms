/*
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Shortest Distance to a Character.
* Memory Usage: 6.7 MB, less than 88.79% of C++ online submissions for Shortest Distance to a Character.
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(), 1e5);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                res[i] = 0;
                int j = i - 1;
                int cnt = 1;
                while(j >= 0) {
                    if (res[j] > cnt) {
                        res[j--] = cnt++;
                    } else {
                        break;
                    }
                }
                j = i + 1;
                cnt = 1;
                while(j < s.size()) {
                    if (s[j] == c) break;
                    if (res[j] > cnt) {
                        res[j++] = cnt++;     
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};