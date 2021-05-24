class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorr(arr.size()+1, 0);
        xorr[1] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            xorr[i+1] = xorr[i]^arr[i];
        }
        vector<int> res;
        for (auto q : queries) {
            res.push_back(xorr[q[1]+1]^xorr[q[0]]);
        }
        return res;
    }
};