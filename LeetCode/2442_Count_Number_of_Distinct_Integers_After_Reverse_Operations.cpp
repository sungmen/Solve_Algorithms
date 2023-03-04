class Solution 
{
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        set<int> s;
        for (auto c : nums)
        {
            s.insert(c);
            string cur = to_string(c);
            reverse(cur.begin(), cur.end());
            s.insert(stoi(cur));
        }
        return s.size();
    }
};