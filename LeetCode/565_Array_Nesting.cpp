class Solution {
private:
    int arr[100001];
public:
    int arrayNesting(vector<int>& nums) {
        memset(arr, -1, sizeof(arr));
        int ans = 0, m = nums.size();
        for (int i = 0; i < m; i++) {
            if (arr[nums[i]] == -1) {
                int tmp = 0, k = i;
                while (arr[nums[k]] == -1) {
                    arr[nums[k]] = nums[k];
                    k = nums[k];
                    tmp++;
                }
                ans = max(ans, tmp);
            }
        }        
        return ans;
    }
};