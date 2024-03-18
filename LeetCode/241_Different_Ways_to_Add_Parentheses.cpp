class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {

    vector<int> ans;
    for (int i = 0; i < expression.size(); i++) {
      char e = expression[i];
      if ('-' != e && '+' != e && '*' != e)
        continue;
      vector<int> l = diffWaysToCompute(expression.substr(0, i));
      vector<int> r = diffWaysToCompute(expression.substr(i + 1));

      for (auto j : l) {
        for (auto k : r) {
          switch (e) {
          case '+': {
            ans.push_back(j + k);
            break;
          }
          case '-': {
            ans.push_back(j - k);
            break;
          }
          case '*': {
            ans.push_back(j * k);
            break;
          }
          }
        }
      }
    }
    if (ans.empty()) {
      ans.push_back(stoi(expression));
    }
    return ans;
  }
};
