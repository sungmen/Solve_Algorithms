class Solution {
public:
  int getLastMoment(int n, vector<int> &left, vector<int> &right) {
    auto _max_element =
        left.empty() ? 0 : *(max_element(left.begin(), left.end()));
    auto _min_element =
        right.empty() ? 0 : n - *(min_element(right.begin(), right.end()));

    return max(_max_element, _min_element);
  }
};
