class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){return to_string(a) + to_string(b) > to_string(b) + to_string(a);});
        string res = "";
        for (auto n : nums) res += to_string(n);
        return (res[0]=='0' && res.size() > 1 ? "0" : res);
    }
};