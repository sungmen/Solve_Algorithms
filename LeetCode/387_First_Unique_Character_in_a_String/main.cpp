/**
* Runtime: 24 ms, faster than 88.77% of C++ online submissions for First Unique Character in a String.
* Memory Usage: 11.1 MB, less than 57.04% of C++ online submissions for First Unique Character in a String.
*/

class Solution {
public:    
    int firstUniqChar(string s) {
        vector<pair<int, int>> v(('z'-'a')+1, make_pair(0, -1));
        for (int i = 0; i < s.size(); i++) {
            v[s[i]-'a'].first++;
            if(v[s[i]-'a'].first == 1) v[s[i]-'a'].second = i;
        }
        int idx = 1e9;
        for (int i = 0; i <= 'z'-'a'; i++) {
            if (v[i].first == 1 && idx > v[i].second) idx = v[i].second;
        }
        if(idx == 1e9) return -1;
        else return idx;
    }
};