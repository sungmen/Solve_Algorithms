class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int n = A.size();
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
      um[A[i]] = 1;
      um[B[i]] = 1;
      ans.push_back((i + 1) * 2 - um.size());
    }
    return ans;
  }
};
