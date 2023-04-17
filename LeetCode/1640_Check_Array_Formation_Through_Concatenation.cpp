class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<vector<int>, int> v;
        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> tmp;
            for (int j = i; j < arr.size(); j++)
            {
                tmp.push_back(arr[j]);
                v[tmp] = 1;
            }
        }
        for (auto piece : pieces)
        {
            if (v.find(piece) == v.end()) return false;
        }
        return true;
    }
};