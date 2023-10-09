class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> v;
    int cnt = 0;
    for (auto c : seq) {
      if (c == '(')
        cnt++;
      v.push_back(cnt % 2);
      if (c != '(')
        cnt--;
    }
    return v;
  }
};
