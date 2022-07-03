class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char, int> m[A.size()-1];
        for (int i = 0; i < A.size()-1; i++) {
            for (int j = 0; j < A[i+1].size(); j++) {
                if (m[i].find(A[i+1][j]) == m[i].end()) {
                    m[i][A[i+1][j]] = 1;
                } else {
                    m[i].find(A[i+1][j])->second++;
                }
            }
        }
        vector<string> ans;
        for (auto i : A[0]) {
            bool chk = true;
            for (int j = 0; j < A.size()-1; j++) {
                if (m[j].find(i) == m[j].end()) {
                    chk = false;
                    break;
                }
            }
            if (chk) {            
                for (int j = 0; j < A.size()-1; j++) {
                    if (m[j].find(i)->second != 1) {
                        m[j].find(i)->second--;
                    } else {
                        m[j].erase(i);
                    }
                }
                string str = "";
                str += i;
                ans.push_back(str);
            }
        }
        return ans;
    }
};