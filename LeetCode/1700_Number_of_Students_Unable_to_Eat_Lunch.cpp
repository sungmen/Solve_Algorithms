class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int one = 0;
    int zero = 0;
    for (auto i : students) {
      if (0 == i) {
        zero++;
      } else {
        one++;
      }
    }
    for (int idx = 0; idx < sandwiches.size(); idx++) {
      if (sandwiches[idx]) {
        if (0 == one) {
          return zero;
        }
        one--;
      } else {
        if (0 == zero) {
          return one;
        }
        zero--;
      }
    }
    return 0;
  }
};
