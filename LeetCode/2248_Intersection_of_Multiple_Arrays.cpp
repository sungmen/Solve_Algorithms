class Solution {
public:
  vector<int> intersection(vector<vector<int>> &nums) {
    int n = nums.size();
    int arr[1001];
    vector<int> answer;
    memset(arr, 0, sizeof(arr));
    for (auto num : nums) {
      for (auto it : num) {
        if (++arr[it] == n) {
          answer.push_back(it);
        }
      }
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};
