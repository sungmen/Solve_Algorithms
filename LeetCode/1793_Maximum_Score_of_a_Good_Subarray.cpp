class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    int ans = nums[k];
    map<int, int> m;
    m[nums[k]] = 1;
    int len = nums.size();
    int i = k;
    int j = k;
    while ((i > 0 || j < len - 1) && i <= j && i <= k && k <= j) {
      if (0 == i)
        j++;
      else if (len - 1 == j)
        i--;
      else if (nums[i - 1] < nums[j + 1])
        j++;
      else
        i--;
      m[nums[i]] = 1;
      m[nums[j]] = 1;
      auto it = m.begin();
      ans = max(ans, it->first * (j - i + 1));
    }
    return ans;
  }
};
