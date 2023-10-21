class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    unordered_map<int, int> um;
    for (int j = 0; j < triplets.size(); j++) {
      int k = 0;
      bool chk = true;
      for (int i = 0; i < 3; i++) {
        if (triplets[j][i] > target[i]) {
          chk = false;
          break;
        } else if (triplets[j][i] == target[i]) {
          k += (1 << i);
        }
      }
      if (false == chk)
        continue;
      if (k == 7)
        return true;
      for (auto it = um.begin(); it != um.end(); it++) {
        if ((it->first | k) == 7)
          return true;
      }
      for (auto it = um.begin(); it != um.end(); it++) {
        um[(it->first | k)] = 1;
      }
      um[k] = 1;
    }
    return false;
  }
};
