class Solution {
public:
    string customSortString(string order, string str) {
        map<char, int> m, n;
        for (auto o : order) m[o]++;
        string fir = "", sec = "";
        int idx = 1;
        for (auto s : str) {
            if (m[s]) {
                n[s]++;                
            } else {
                sec += s;
            }
        }
        for (auto o : order) {
            if (n[o]) {
                for (int i = 0; i < n[o]; i++) {
                    fir += o;
                }
            }
        }
        return fir + sec;
    }
};