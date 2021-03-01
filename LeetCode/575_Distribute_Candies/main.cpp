class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int i = 0, tmp = -1e5-1;
        for (auto j : candyType) {
            if (tmp != j) {
                tmp = j;
                i++;
            }
        }
        return min(candyType.size()/2, i);
    }
};