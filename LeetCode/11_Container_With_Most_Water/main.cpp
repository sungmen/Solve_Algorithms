class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size()-1;
        while(l < r) {
            int tmp = min(height[r], height[l]) * (r-l);
            if (tmp > result) result = tmp;
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return result;
    }
};