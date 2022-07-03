class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for (int i = 0; i < rowIndex; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j < ans.size(); j++)
            {
                tmp.push_back(ans[j] + ans[j-1]);
            }
            tmp.push_back(1);
            ans = tmp;
        }        
        return ans;
    }
};