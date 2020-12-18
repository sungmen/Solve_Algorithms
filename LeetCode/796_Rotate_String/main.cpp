/*
    Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
    Memory Usage: 6.9 MB, less than 20.28% of C++ online submissions for Rotate String.
*/

class Solution {
public:
    bool rotateString(string A, string B) {
        if (!A.size() && !B.size()) return true;
        vector<int> t;
        for (int i = 0; i < A.size(); i++) if(B[i] == A[0]) t.push_back(i);
        for (int i = 0; i < t.size(); i++) {
            string temp = "";
            temp += B.substr(t[i], B.size() - t[i]);
            temp += B.substr(0, t[i]);
            int cnt = 0;
            for (int i = 0; i < A.size() ;i++) {
                if (A[i] == temp[i]) cnt++;
            }
            if(cnt == A.size()) return true;
        }
        
        return false;
    }
};