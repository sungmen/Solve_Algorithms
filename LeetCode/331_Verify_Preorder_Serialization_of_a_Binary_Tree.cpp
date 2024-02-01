class Solution {
public:
  bool isValidSerialization(string preorder) {
    int cnt = 1;
    int m = (preorder[0] != '#');
    for (int i = 0; i < preorder.size(); i++) {
      if (preorder[i] == ',') {
        cnt--;
        if (cnt < 0)
          return false;
        if (m == 1)
          cnt += 2;
        m = (preorder[i + 1] != '#');
      }
    }
    cnt--;
    if (m == 1)
      cnt += 2;
    if (cnt < 0)
      return false;
    return (!cnt);
  }
};
