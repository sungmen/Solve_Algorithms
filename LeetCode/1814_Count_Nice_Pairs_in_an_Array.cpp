constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int answer = 0;        
        unordered_map<int, int> um;
        for (auto num : nums) {
            string tmpNum = to_string(num);
            reverse(tmpNum.begin(), tmpNum.end());
            answer += (um[num - stoi(tmpNum)]++);
            answer %= MOD;
        }
        return answer;
    }
};