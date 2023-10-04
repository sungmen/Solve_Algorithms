class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        int answer = 0;
        vector<pair<int, int>> v;
        for (auto b : boxTypes)
        {
            v.push_back({-b[1],b[0]});
        }
        sort(v.begin(), v.end());
        for (auto i : v)
        {
            int n = -i.first;
            int t = i.second;
            int p = (t < truckSize)? t : truckSize;
            truckSize -= t;
            answer += (p * n);
            if (truckSize <= 0) break;
        }
        return answer;    
    }
};