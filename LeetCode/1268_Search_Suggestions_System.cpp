class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        map<string, vector<string>> m;
        for (auto product : products)
        {
            string tmpstr = "";
            for (auto produc : product)
            {
                tmpstr += produc;
                if (m[tmpstr].size() < 3)
                {
                    m[tmpstr].push_back(product);
                }
            }
        }
        string str = "";
        for (auto search : searchWord)
        {
            str += search;
            ans.push_back(m[str]);
        }
        
        return ans;
    }
};