class Solution {
public:
  int minimumOperations(string num) {
    int n = num.size();
    int removeCnt = 0;
    int zero = -1;
    int five = -1;
    for (int i = n - 1; i >= 0; i--) {
      switch (num[i]) {
      case '0': {
        if (-1 == zero) {
          zero = i;
        } else {
          return (zero - i - 1) + (n - zero - 1);
        }
        break;
      }
      case '5': {
        if (-1 == five) {
          five = i;
        }
        if (-1 != zero) {
          return (zero - i - 1) + (n - zero - 1);
        }
        break;
      }
      case '2':
      case '7': {
        if (-1 == five) {
          break;
        }
        return (five - i - 1) + (n - five - 1);
        break;
      }
      }
    }
    return (-1 == zero ? n : n - 1);
  }
};
