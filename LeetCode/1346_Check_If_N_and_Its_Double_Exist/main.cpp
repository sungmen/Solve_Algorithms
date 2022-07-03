class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> m;
        for (auto i : arr) ++m[i];
        for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->first == 0 && it->second > 1) return true;
            if (it->first != 0 && it->first % 2 == 0 && m.find(it->first / 2) != m.end()) {
                return true;
            }
        }
        return false;
    }
};