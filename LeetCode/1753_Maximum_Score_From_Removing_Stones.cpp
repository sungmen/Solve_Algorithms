class Solution 
{
public:
    int maximumScore(int a, int b, int c) 
    {
        vector<int> r;
        r.push_back(a);
        r.push_back(b);
        r.push_back(c);
        sort(r.begin(), r.end());
        
        return min(r[0]+r[1], accumulate(r.begin(), r.end(), 0)/2);
    }
};