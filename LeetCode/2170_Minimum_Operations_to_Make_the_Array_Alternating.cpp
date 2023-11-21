bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; }

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int n1 = 0;
    int n2 = 0;
    int n = nums.size();
    if (1 == n)
      return 0;
    if (2 == n)
      return nums[0] == nums[1];
    int a1 = nums[0];
    int a2 = nums[1];
    unordered_map<int, int> um1, um2;
    for (int i = 0; i < n; i++) {
      if (i % 2) {
        n1++;
        um1[nums[i]]--;
      } else {
        n2++;
        um2[nums[i]]--;
      }
    }
    vector<pair<int, int>> v1(um1.begin(), um1.end()),
        v2(um2.begin(), um2.end());
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    if (it1->first == it2->first) {
      auto tmp = v1.begin();
      tmp++;
      bool chk1 = false;
      bool chk2 = false;
      if (tmp == v1.end())
        chk1 = 1;
      auto tmp2 = v2.begin();
      tmp2++;
      if (tmp2 == v2.end())
        chk2 = 1;
      if (chk1 && chk2)
        return (-it1->second > -it2->second ? -it2->second : -it1->second);
      int t1 = 1e9;
      if (!chk2)
        t1 = n1 + it1->second + n2 + tmp2->second;
      int t2 = 1e9;
      if (!chk1)
        t2 = n1 + tmp->second + n2 + it2->second;
      if (chk1)
        return t1;
      if (chk2)
        return t2;
      return (t1 > t2 ? t2 : t1);
    }
    return n1 + v1.begin()->second + n2 + v2.begin()->second;
  }
};
