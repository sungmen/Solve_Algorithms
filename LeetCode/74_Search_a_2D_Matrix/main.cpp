/*
    Runtime: 4 ms, faster than 96.32% of C++ online submissions for Search a 2D Matrix.
    Memory Usage: 9.9 MB, less than 41.73% of C++ online submissions for Search a 2D Matrix.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()|| !matrix[0].size()) return false;
        int cl = 0;
        int cr = matrix.size() - 1;
        int cidx = 0;
        int mid = 0;
        if (matrix[0][0] > target) return false;
        if (matrix[matrix.size()-1][matrix[0].size()-1] < target) return false;
        if (matrix[matrix.size()-1][0] <= target) {
            if(matrix[matrix.size()-1][0] == target) return true;
            cidx = matrix.size() - 1;
        } else {
            while(cl < cr) {
                mid = (cl + cr) / 2;
                if (matrix[mid][0] == target) return true;
                if (matrix[mid][0] > target) cr = mid;
                else cl = mid + 1;
            }
            cidx = cl - 1;
        }
        
        if(matrix[cidx][matrix[0].size()-1] < target) return false;
        int rl = 0;
        int rr = matrix[0].size() - 1;
        mid = 0;
        if(matrix[cidx][rr] == target) return true;
        while(rl < rr) {
            mid = (rl + rr) / 2;
            if(matrix[cidx][mid] == target) return true;
            if(matrix[cidx][mid] > target) rr = mid;
            else rl = mid + 1;
        }
        
        return false;
    }
};