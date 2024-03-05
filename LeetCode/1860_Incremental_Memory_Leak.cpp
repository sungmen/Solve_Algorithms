class Solution {
public:
  vector<int> memLeak(int memory1, int memory2) {
    int crashTime = 1;
    while (true) {
      if (memory1 >= memory2 && memory1 >= crashTime) {
        memory1 -= crashTime++;
      } else if (memory2 > memory1 && memory2 >= crashTime) {
        memory2 -= crashTime++;
      } else {
        break;
      }
    }

    return {crashTime, memory1, memory2};
  }
};
