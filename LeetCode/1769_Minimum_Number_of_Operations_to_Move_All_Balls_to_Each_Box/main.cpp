/**
* Runtime: 144 ms, faster than 50.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
* Memory Usage: 9.3 MB, less than 50.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> one;
        for (int i = 0; i < boxes.size(); i++) if (boxes[i] == '1') one.push_back(i);
        vector<int> res(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); i++) {
            for (auto j : one) {
                if (j != i) {
                    res[i] += abs(j - i);
                }
            }
        }
        return res;
    }
};