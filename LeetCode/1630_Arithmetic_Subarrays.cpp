class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    int n = l.size();
    vector<bool> ans;
    for (int i = 0; i < n; i++) {
      int ll = l[i];
      int rr = r[i];
      vector<int> v;
      for (int j = ll; j <= rr; j++)
        v.push_back(nums[j]);
      sort(v.begin(), v.end());
      int d = v[1] - v[0];
      bool chk = true;
      for (int j = 2; j < v.size(); j++) {
        int f = v[j] - v[j - 1];
        if (d != f) {
          chk = false;
          break;
        }
      }
      ans.push_back(chk);
    }
    return ans;
  }
};
