class Solution {
public:
    int getMinSwaps(string num, int k) {
        string next = num;
        while(k--) {
            next_permutation(next.begin(), next.end());
        }
        int ans = 0;
        for (int i = 0; i < num.size(); i++) {
            int j;
            for (j = i; j < num.size() && num[i] != next[j]; j++);
            for (int k = j; k > i; k--) {
                swap(next[k], next[k-1]);
                ans++;
            }
        }
        return ans;
    }
};