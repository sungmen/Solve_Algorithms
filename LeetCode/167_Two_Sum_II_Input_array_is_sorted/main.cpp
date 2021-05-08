class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map <int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            m[numbers[i]] = i + 1;
        }
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(target - numbers[i]) != m.end()) {
                return {i + 1, m.find(target - numbers[i])->second};
            }
        }
        return {};
    }
};