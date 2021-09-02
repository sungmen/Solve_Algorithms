class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (!(k % size)) return;
        else {
            int r = size - (k % size);
            vector<int> v(size);
            int i = 0;
            while (i < size) {
                v[i] = nums[r++];
                if (r >= size) r = 0;
                ++i;
            }
            nums = v;
        }
    }
};