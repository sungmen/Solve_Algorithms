class Solution {
public:
  int minLength(string s) {
    stack<char> st;
    for (auto c : s) {
      if (true == st.empty()) {
        st.push(c);
        continue;
      }
      if (('B' == c && 'A' == st.top()) || ('D' == c && 'C' == st.top())) {
        st.pop();
        continue;
      }
      st.push(c);
    }
    return st.size();
  }
};
