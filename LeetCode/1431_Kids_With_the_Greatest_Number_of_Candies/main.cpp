class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> bv;
        for (auto i : candies) {
            if(i+extraCandies >= m) bv.emplace_back(true);
            else bv.emplace_back(false);
        }
        return bv;
    }
};