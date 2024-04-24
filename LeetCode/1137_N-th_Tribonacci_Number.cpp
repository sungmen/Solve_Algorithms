class Solution {
public:
  int tribonacci(int n) {
    int arr[38];
    memset(arr, 0, sizeof(arr));
    arr[2] = arr[1] = 1;
    for (int i = 3; i < 38; i++) {
      arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
  }
};
