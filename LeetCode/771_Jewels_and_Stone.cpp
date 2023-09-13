class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_map<char, int> um;
        for (auto j : jewels)
        {
            um[j]++;
        }
        int cnt = 0;
        for (auto s : stones)
        {
            if (um.find(s) != um.end()) cnt++;
        }
        return cnt;
    }
};