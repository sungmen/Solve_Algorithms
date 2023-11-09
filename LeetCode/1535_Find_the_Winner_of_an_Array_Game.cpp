class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    int i = 0;
    int answer = arr[i++];
    int win_count = 0;
    for (; i < arr.size(); i++) {
      if (answer < arr[i]) {
        answer = arr[i];
        win_count = 0;
      }
      if (++win_count == k)
        return answer;
    }

    return answer;
  }
};
