class Solution {
private:
    int arr1[7], arr2[7], sum[7], dup[7];
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int s = tops.size();
        int t = -1;
        for (int i = 0; i < s; i++) {
            arr1[tops[i]]++;
            arr2[bottoms[i]]++;
            if (tops[i]==bottoms[i]) {
                dup[tops[i]]++;
                sum[tops[i]]++;
            } else {
                sum[tops[i]]++;
                sum[bottoms[i]]++;
            }
        }
        if (sum[tops[s-1]] == s) {
            return s - max(arr1[tops[s-1]], arr2[tops[s-1]]);
        } else if (sum[bottoms[s-1]] == s) {
            return s - max(arr1[bottoms[s-1]], arr2[bottoms[s-1]]);
        }
        return t;
    }
};