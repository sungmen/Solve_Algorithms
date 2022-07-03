class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) sum += arr[i];
        int s = 3;
        while (s <= arr.size()) {
            for (int i = 0; i <= arr.size() - s; i++) {
                for (int j = i; j < i + s; j ++) {
                    sum += arr[j];
                }
            }
            s += 2;
        }
        return sum;
    }
};