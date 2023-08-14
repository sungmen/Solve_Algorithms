class Solution 
{
public:
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        auto compare = [] (string& s1, string& s2)
        {   
            if (s1.size() != s2.size())
                return s1.size() > s2.size();
            return s1 > s2;
        };
        priority_queue<string, vector<string>, decltype(compare)> pq(compare);
        for (auto c : nums)
        {
            pq.push(c);
        }
        int p = nums.size() - k;
        while (p-- && !pq.empty()) pq.pop();
        return pq.top();
    }
};