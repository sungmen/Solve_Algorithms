class Solution {
public:
  vector<long long> distance(vector<int> &nums) {
    vector<long long> ans;
    unordered_map<int, pair<long long, int>> um;
    vector<pair<long long, int>> res;

    for (int i = 0; i < nums.size(); i++) {
      um[nums[i]] = {um[nums[i]].first + i, um[nums[i]].second + 1};
      res.push_back({um[nums[i]].first, um[nums[i]].second});
    }

    for (int i = 0; i < nums.size(); i++) {
      long long j = ((long long)i * res[i].second) - res[i].first;
      long long k = (um[nums[i]].first - res[i].first) -
                    ((long long)i * (um[nums[i]].second - res[i].second));

      ans.push_back(j + k);
    }

    return ans;
  }
};
