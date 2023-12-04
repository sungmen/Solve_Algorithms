class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while (r - l + 1 > k) {
      int f = abs(x - arr[l]);
      int s = abs(x - arr[r]);
      if (f > s)
        l++;
      else
        r--;
    }
    return vector<int>(arr.begin() + l, arr.begin() + r + 1);
  }
};
