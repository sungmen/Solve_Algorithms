class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool chk = 0;
        int n = arr.size();
        int b = arr[0];
        for (int i = 1; i < n; ++i) {
            if (b == arr[i]) return false;
            else if (!chk) {
                if (b > arr[i]) {
                    if (i == 1) return false;
                    chk = 1;
                }
            } else {
                if (b < arr[i]) return false;
            }
            b = arr[i];
        }
        if (chk) return true;
        else return false;
    }
};