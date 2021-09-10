class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> m;
        for (auto n : nums) {
            m[n] = 1;
        }
        string result(nums.size(), '0');
        if (m.find(result) == m.end()) return result;
        for (int i = 0; i < nums.size(); ++i) {
            string tmp = result;
            tmp[i] = '1';
            if (m.find(tmp) == m.end()) return tmp;
        } 
        return result;
    }
};