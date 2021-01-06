/**
* Runtime: 4 ms, faster than 98.49% of C++ online submissions for Kth Missing Positive Number.
* Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Kth Missing Positive Number.
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        int i = 1;
        while(true) {
            if(j < arr.size() && arr[j] == i) j++;
            if (i - j == k) return i;
            i++;
        }
        return 0;
    }
};