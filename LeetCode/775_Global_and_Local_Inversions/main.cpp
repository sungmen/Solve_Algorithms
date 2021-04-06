class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int tmp = 0, size_ = A.size();
        for (int i = 0; i < size_ - 2; ++i) {
            tmp = max(tmp, A[i]);
            if (tmp > A[i+2]) return false;
        }
        return true;
    }
};