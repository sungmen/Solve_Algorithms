/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
* Memory Usage: 7 MB, less than 16.45% of C++ online submissions for Word Pattern.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> splitText(istream_iterator<string>{iss}, istream_iterator<string>());
        if (pattern.size() != splitText.size()) return false;
        map<char, string> m;
        map<string, char> m2;
        for (int i = 0; i < pattern.size(); i++) {
            if (m.find(pattern[i]) != m.end()) {
                if (m.find(pattern[i])->second != splitText[i]) {
                    return false;
                }
            } else {
                m[pattern[i]] = splitText[i];
            }
            if (m2.find(splitText[i]) != m2.end()) {
                if (m2.find(splitText[i]) -> second != pattern[i]) {
                    return false;
                }
            } else {
                m2[splitText[i]] = pattern[i];
            }
        }
        return true;
    }
};