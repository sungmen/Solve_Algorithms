class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    vector<vector<int>> answer;
    int l = 0, r = 0, left = 0, right = 0;
    while (l < firstList.size() && r < secondList.size()) {
      vector<int> curF = firstList[l];
      vector<int> curS = secondList[r];
      left = max(curF[0], curS[0]);
      right = min(curF[1], curS[1]);
      if (left <= right) {
        answer.push_back({left, right});
      }
      if (curF[1] < curS[1]) {
        l++;
      } else {
        r++;
      }
    }
    return answer;
  }
};
