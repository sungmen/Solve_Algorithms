class Solution {
public:
  int cal(stack<string> &stk) {
    int res = 0;
    while (false == stk.empty() && (stk.top() != "+(" && stk.top() != "-(")) {
      res += stoi(stk.top());
      stk.pop();
    }
    if (false == stk.empty() && (stk.top() != "+(" || stk.top() != "-(")) {
      if (stk.top() == "-(")
        res = -res;
      stk.pop();
    }
    return res;
  }
  int calculate(string s) {
    stack<string> stk;
    string str = "";
    for (auto it : s) {
      if (it == ' ')
        continue;
      if (it == '(') {
        if (false == stk.empty() && stk.top() == "-") {
          stk.pop();
          stk.push("-(");
        } else {
          if (false == stk.empty() && stk.top() == "+")
            stk.pop();
          stk.push("+(");
        }
        continue;
      }
      if (it == ')') {
        if (str != "")
          stk.push(str);
        str = "";
        stk.push(to_string(cal(stk)));
        continue;
      }
      if (it == '+' || it == '-') {
        if (str != "")
          stk.push(str);
        str = "";
        string tmp = "";
        tmp += it;
        stk.push(tmp);
        continue;
      }
      if (str == "" && false == stk.empty() &&
          ("+" == stk.top() || "-" == stk.top())) {
        str += stk.top();
        stk.pop();
      } else if (str == "") {
        str += '+';
      }
      str += it;
    }
    if (str == "")
      return cal(stk);
    stk.push(str);
    return cal(stk);
  }
};
